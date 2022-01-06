#include "shaders.h"

std::string getFileContents(std::string fileName) {
	std::ifstream in(fileName.c_str(), std::ios::binary);

	if (in) {
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shaders::Shaders(std::string vertexFileName, std::string fragmentFileName) : vertexFileName(vertexFileName), fragmentFileName(fragmentFileName) {
	const char* vertexSource = getFileContents(vertexFileName).c_str();
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	const char* fragmentSource = getFileContents(fragmentFileName).c_str();
    GLuint fragmentShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shaders::activate() {
	glUseProgram(program);
}