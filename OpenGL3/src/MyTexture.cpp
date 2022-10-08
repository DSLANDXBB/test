#include "MyTexture.h"
#include <iostream>


MyTexture::MyTexture(const unsigned int textureType)
{
		glGenTextures(1, &textureId);
		this->textureType = textureType;
}

void MyTexture::loadTexture2D(const std::string& texturePath)
{
	int x, y, nrChannels;
	unsigned char* data = stbi_load(texturePath.c_str(), &x, &y, &nrChannels, 0);
	if(data)
	{
		glTexImage2D(textureType, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(textureType);
	}
	else
	{
		std::cout << "texture load error in MyTexTure.cpp" << std::endl;
		exit(0);
	}
	stbi_image_free(data);
}

void MyTexture::bindTexture2D(unsigned int texturePos)
{
	glActiveTexture(texturePos);
	glBindTexture(textureType, this->textureId);
}

void MyTexture::unbindTexture2D()
{
	glBindTexture(textureType, 0);
}

void MyTexture::setTextureMode2D(const unsigned int& wrap, const unsigned int& filter)
{
	glTexParameteri(textureType, GL_TEXTURE_WRAP_S, wrap);
	glTexParameteri(textureType, GL_TEXTURE_WRAP_S, wrap);
	glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, filter);
}
