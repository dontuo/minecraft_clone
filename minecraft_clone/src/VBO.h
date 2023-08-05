#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VBO
{
public:
	unsigned int mVBO;

	VBO() 
	{
		glGenBuffers(1, &mVBO);
	}

	void bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	}

	void push_data(int size, void *data, GLenum type) 
	{
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, size, data, type);
	}

	~VBO()
	{
		glDeleteBuffers(1, &mVBO);
	}
};