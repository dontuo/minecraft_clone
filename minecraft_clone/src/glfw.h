#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLFW
{
public:
	GLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	~GLFW()
	{
		glfwTerminate();
	}
};

