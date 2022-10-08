#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

typedef unsigned int u_int;

class MyShader
{
private:
	u_int programId;
public:
	MyShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	void run();
	//uniform¹¤¾ßº¯Êý
	void setUniformInt(const std::string &name, int &value);
	void setUniformFloat(const std::string& name, float& value);
};