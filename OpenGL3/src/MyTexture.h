#pragma once
#include "MyTexture.h"
#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class MyTexture
{
private:
	unsigned int textureId;
	unsigned int textureType;
public:
	MyTexture(const unsigned int textureType);
	void loadTexture2D(const std::string &texturePath);
	void bindTexture2D(unsigned int texturePos);
	void unbindTexture2D();
	void setTextureMode2D(const unsigned int &wrap, const unsigned int &filter);
};