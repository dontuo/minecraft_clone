#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &mVAO);
}

void VAO::bind()
{
	glBindVertexArray(mVAO);
}

void VAO::push_data(int index, int size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)
{
	bind();
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &mVAO);
}