#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class ShaderTools
{
public:
	static void ReadFileSrc(std::string &src, const std::string &filename);
	static unsigned int CompileShader(const std::string& src, const unsigned int& shaderType);
	static unsigned int getProgram(const unsigned int& vertexShader, const unsigned int& fragmentShader);
};

