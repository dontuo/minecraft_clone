#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VAO
{
public:
	unsigned int mVAO;
	VAO();
	void bind();
	void push_data(int index, int size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
	~VAO();
};

