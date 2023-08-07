#include "VBO.h"


VBO::VBO()
{
	glGenBuffers(1, &mVBO);
}

void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
}

void VBO::push_data(int size, void* data, GLenum type)
{
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, size, data, type);
}

VBO::~VBO()
{
	glDeleteBuffers(1, &mVBO);
}