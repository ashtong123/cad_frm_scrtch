#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description);
void close_window_callback(GLFWwindow* window);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
	//setup error callback
	glfwSetErrorCallback(error_callback);
	
	//initialize glfw
	if (!glfwInit()) {
		printf("Failed to initialize glfw\n");// Initialization failed
	}
	else {
		printf("glfw initializated successfully\n");
	}
	
	//create window and glfw/openGL admin
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		printf("Failed to open window\n");
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	
	//setup callbacks
	glfwSetWindowCloseCallback(window, close_window_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback); 	
	//render something
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	
	//window maintenannce
	while (!glfwWindowShouldClose(window))
	{
		// Keep running
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	
	//terminate glfw session
	glfwTerminate();
	printf("glfw terminated successfully\n");
	//keep terminal open until prompted by user to close
	printf("Press ENTER to close program");
	while(!getchar());
	
	return 0;
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void close_window_callback(GLFWwindow* window)
{
	printf("Window closed by EXIT button click\n");
	return;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
	printf("Window closed by ESC key press\n");
}

void framebuffer_resize_callback(GLFWwindow* window)
{
	printf("Window closed by EXIT button click\n");
	return;
}