#include "window.h"

Window::Window(unsigned int width, unsigned int height, const char* name)
	:m_width{ width }, m_height{ height }
{
	m_window = glfwCreateWindow(width, height, name, NULL, NULL);

	if (m_window == NULL)
	{
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to initialize GLAD");
	}

	glEnable(GL_DEPTH_TEST);
}

void Window::clear()
{
	glClearColor(0.2f, 0.5f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuff()
{
	glfwSwapBuffers(m_window);
}

void Window::eventUpdate()
{

	glfwPollEvents();
}