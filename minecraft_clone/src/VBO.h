#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VBO
{
public:
	unsigned int mVBO;
	VBO();
	void bind();
	void push_data(int size, void* data, GLenum type);
	~VBO();
};
