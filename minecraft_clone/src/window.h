#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	GLFWwindow* m_window;
	unsigned int m_width;
	unsigned int m_height;

	Window(unsigned int width, unsigned int height, const char* name, void (*framebuffer_size_callback)(GLFWwindow*, int, int))
		:m_width{width}, m_height{height}
	{
		// initialize the window
		m_window = glfwCreateWindow(width, height, name, NULL, NULL);
		
		if (m_window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(m_window);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
	}
	void use(void (*framebuffer_size_callback)(GLFWwindow*, int, int))
	{
		glfwMakeContextCurrent(m_window);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
	}

	

	void swapBuff()
	{
		glClearColor(0.2f, 0.5f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(m_window);
	}
};