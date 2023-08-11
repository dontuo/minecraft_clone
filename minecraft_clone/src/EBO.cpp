#include "EBO.h"

EBO::EBO()
{
	glGenBuffers(1, &mEBO);
}
void EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
}
void EBO::push_data(int size, void* data, GLenum type)
{
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
EBO::~EBO()
{
	glDeleteBuffers(1, &mEBO);
}