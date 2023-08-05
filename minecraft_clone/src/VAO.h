#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VAO
{
public:
	unsigned int mVAO;

	VAO()
	{
		glGenVertexArrays(1, &mVAO);
	}

	void bind()
	{
		glBindVertexArray(mVAO);
	}

	void push_data(int index, int size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
	{
		bind();
		glVertexAttribPointer(index, size, type, normalized, stride, pointer);
		glEnableVertexAttribArray(index);
	}

	~VAO()
	{
		glDeleteVertexArrays(1, &mVAO);
	}
};