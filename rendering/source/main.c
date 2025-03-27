#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	if (!glfwInit())
	{
		printf("Failed to initialize glfw\n");// Initialization failed
	}
	
	printf("glfw initializated successfully\n");
	return 0;
}