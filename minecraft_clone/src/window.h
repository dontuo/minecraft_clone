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
		m_window = glfwCreateWindow(width, height, name, NULL, NULL);
		
		if (m_window == NULL)
		{
			throw std::runtime_error("Failed to create GLFW window");
		}

		glfwMakeContextCurrent(m_window);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

		//glEnable(GL_DEPTH_TEST);
	}

	void clear()
	{
		glClearColor(0.2f, 0.5f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void swapBuff()
	{
		glfwSwapBuffers(m_window);		
	}

	void eventUpdate()
	{
		glfwPollEvents();
	}
};