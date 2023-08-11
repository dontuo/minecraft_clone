#include "texture.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>

Texture::Texture(const char* path, GLint format, GLint type)
{
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	m_data = stbi_load(path, &m_texWidth, &m_texHeight, &m_nrChannels, 0);

	if (m_data)
	{
		glBindTexture(GL_TEXTURE_2D, m_id);
		glTexImage2D(GL_TEXTURE_2D, 0, format, m_texWidth, m_texHeight, 0, type, GL_UNSIGNED_BYTE, m_data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		throw std::runtime_error("Failed to load texture =/");
	}
}

/*Texture::~Texture()
{
	//stbi_image_free(m_data);
	glActiveTexture(0);
}*/

void Texture::bind(GLenum texture_id = 0)
{
	glActiveTexture(GL_TEXTURE0 + texture_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
}