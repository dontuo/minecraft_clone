#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class EBO
{
public:
	unsigned int mEBO;
	EBO();
	void bind();
	void push_data(int size, void* data, GLenum type);
	~EBO();
};