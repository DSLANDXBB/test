#include "MyShader.h"
#include "ShaderTools.h"
#include <fstream>
#include <sstream>


MyShader::MyShader(const std::string &vertexShaderPath, const std::string &fragmentShaderPath)
{
	/*get shaderSrc*/
	std::string vs, fs;
	ShaderTools::ReadFileSrc(vs, vertexShaderPath);
	ShaderTools::ReadFileSrc(fs, fragmentShaderPath);
	std::cout << vs << std::endl;
	std::cout << fs << std::endl;
	/*--------------*/

	/*Compile Shader*/
	u_int vertexShader, fragmentShader;
	vertexShader = ShaderTools::CompileShader(vs, GL_VERTEX_SHADER);
	fragmentShader = ShaderTools::CompileShader(fs, GL_FRAGMENT_SHADER);
	/*--------------*/

	/*Link Program*/
	this->programId = ShaderTools::getProgram(vertexShader, fragmentShader);
	/*--------------*/
}

void MyShader::run()
{
	glUseProgram(this->programId);
}

void MyShader::setUniformInt(const std::string& name, int& value)
{
	int vertexUniformLocation = glGetUniformLocation(this->programId, name.c_str());
	glUniform1i(vertexUniformLocation, value);
}

void MyShader::setUniformFloat(const std::string& name, float& value)
{
	int vertexUniformLocation = glGetUniformLocation(this->programId, name.c_str());
	glUniform1f(vertexUniformLocation, value);
}
