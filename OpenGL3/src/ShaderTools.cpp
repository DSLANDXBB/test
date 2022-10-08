#include "ShaderTools.h"
#include <fstream>
#include <sstream>


void ShaderTools::ReadFileSrc(std::string& src, const std::string& filename)
{
	std::string line;
	std::stringstream ss;

	/*Read Vertex*/
	std::ifstream file(filename, std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: file open error!!" << std::endl;
		exit(0);
	}
	while (getline(file, line))
	{
		ss << line << std::endl;
	}
	/*--------------*/
	file.close();
	src = ss.str();
}

unsigned int ShaderTools::CompileShader(const std::string& src, const unsigned int& shaderType)
{
	unsigned int shader;
	shader = glCreateShader(shaderType);
	const char* shaderSrc = src.c_str();
	glShaderSource(shader, 1, &shaderSrc, nullptr);

	int success;
	char infoLog[512];
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cout << infoLog << std::endl;
	}
	return shader;
}

unsigned int ShaderTools::getProgram(const unsigned int& vertexShader, const unsigned int& fragmentShader)
{
	unsigned int program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	int success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		std::cout << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}
