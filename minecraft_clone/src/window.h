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
	Window(unsigned int width, unsigned int height, const char* name);
	void clear();
	void swapBuff();
	void eventUpdate();
};