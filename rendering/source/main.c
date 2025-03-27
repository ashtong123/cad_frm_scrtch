#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description);

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
	//create window
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		printf("Failed to open window\n");
	}
	//keep window open until prompted by user to close
	printf("Press enter to close window\n");
	while(!getchar());
	//terminate glfw session
	glfwTerminate();
	printf("glfw terminated successfully\n");
	
	return 0;
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
