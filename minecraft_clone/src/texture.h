#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Texture
{
public:
	unsigned int m_id;
	unsigned char* m_data;
	int m_texWidth, m_texHeight, m_nrChannels;

	Texture(const char* path, GLint format, GLint type);

    /*~Texture();*/

	void bind(GLenum texture_id);
};