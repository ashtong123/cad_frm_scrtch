#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//function prototypes
void error_callback(int error, const char* description);
void close_window_callback(GLFWwindow* window);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebuffer_resize_callback(GLFWwindow* window, int width, int height);

//shaders
//vertex shader
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
//fragment shader
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0"; 

//functions
//error callback
void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
	return;
}

void close_window_callback(GLFWwindow* window)
{
	printf("Window closed by EXIT button click\n");
	return;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
		printf("Window closed by ESC key press\n");
	}
	else if (key == GLFW_KEY_R && action == GLFW_PRESS && mods == GLFW_MOD_ALT) {
		glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
	}
	else if (key == GLFW_KEY_G && action == GLFW_PRESS && mods == GLFW_MOD_ALT) {
		glClearColor(0.0f, 0.3f, 0.0f, 1.0f);
	}
	else if (key == GLFW_KEY_B && action == GLFW_PRESS && mods == GLFW_MOD_ALT) {
		glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	}
	return;
}

void framebuffer_resize_callback(GLFWwindow* window, int width, int height)
{
	//maintain the window color as resizing occurs, if this bit is left out,
	//additional regions of the window created by a resize will be black, rather than
	//the same color as the rest of the window
	glfwGetFramebufferSize(window, &width, &height);
	
	//get current clear color
	GLfloat bkColor[4]; 
	glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
	
	//set new window with existing bkColor
	glClearColor(bkColor[0], bkColor[1], bkColor[2], bkColor[3]);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glViewport(0, 0, width, height);
	
	glfwSwapBuffers(window); //swap front and back buffer after rendering
	printf("Window framebuffer resized to %dx%d\n", width, height);
	return;
}

int main()
{
	//setup vertices data
	float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
	};
	
	//setup error callback
	glfwSetErrorCallback(error_callback);
	
	//initialize glfw
	if (!glfwInit()) {
		printf("Failed to initialize glfw\n");// Initialization failed
		exit(EXIT_FAILURE);
	}
	else {
		printf("glfw initializated successfully\n");
	}
	
	//glfw/openGL admin
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	

	//create window
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		printf("Failed to open window\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	//setup callbacks
	glfwSetWindowCloseCallback(window, close_window_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback); 
	
	//setup openGL context
	glfwMakeContextCurrent(window);
	gladLoadGL();
	
	glfwSwapInterval(1); //set swap interval
	
	double time = glfwGetTime(); //get time
	printf("Start time: %f\n", time);

	//generate a vertex buffer object (VBO)
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	//generate a vertex array object (VAO)
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	
	//CREATE SHADERS
	//create vertex shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//create fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//compile shaders
	//compile vertex shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	//compile fragment shader
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	//check if shader compilation was successful
	int  success;
	char infoLog[512];
	//vertex shader compilation error check
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
	}
	//fragment shader compilation error check
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
	}
	
	//LINK SHADERS
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//check whether linking was successful
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	//output error message if not
	if(!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		printf("ERROR::SHADER::PROGRAM::LINKING::FAILED\n%s\n", infoLog);
	}
	//Delete individual shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader); 
	
	//RENDER A TRIANGLE	INITIALIZATION 
	//copy vertices into a buffer
	// 1. Bind VAO
	glBindVertexArray(VAO);
	// 2. copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3. then set the vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);  


	//set initial window color
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//window maintenance
	while (!glfwWindowShouldClose(window))
	{
		//SET WINDOW COLOR
		int width, height;
		
		glfwGetFramebufferSize(window, &width, &height);
		
		//get current clear color
		GLfloat bkColor[4]; 
		glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
		
		//set new window with existing bkColor
		glClearColor(bkColor[0], bkColor[1], bkColor[2], bkColor[3]);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glViewport(0, 0, width, height);
		
		//RENDER A TRIANGLE DRAWING IN LOOP
		// 4. use our shader program when we want to render an object
		glUseProgram(shaderProgram);
		// 5. Bind our VAO created previously
		glBindVertexArray(VAO);
		// 6. now draw the object 
		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		glfwSwapBuffers(window); //swap front and back buffer after rendering
		
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	
	//terminate glfw session
	glfwTerminate();
	printf("glfw terminated successfully\n");
	//keep terminal open until prompted by user to close
	printf("Press ENTER to close program");
	while(!getchar());
	exit(EXIT_SUCCESS);
	
	return 0;
}

