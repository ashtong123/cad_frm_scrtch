#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description);
void close_window_callback(GLFWwindow* window);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebuffer_resize_callback(GLFWwindow* window, int width, int height);

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
	
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSwapInterval(1); //set swap interval
	double time = glfwGetTime(); //get time
	printf("Start time: %f\n", time);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//window maintenannce
	while (!glfwWindowShouldClose(window))
	{
		//render something ... WORK HERE
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		//get current clear color
		GLfloat bkColor[4]; 
		glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
		
		//set new window with existing bkColor
		glClearColor(bkColor[0], bkColor[1], bkColor[2], bkColor[3]);
		glClear(GL_COLOR_BUFFER_BIT);
		glViewport(0, 0, width, height);
		
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

