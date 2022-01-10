#include "shaders.h"

void getFileContents(const std::string& filepath) {
  FILE* file = fopen(path, "r");

    fseek(file, 0L, SEEK_END);
    long __length = ftell(file) * sizeof(char);
    fseek(file, 0L, SEEK_SET);

    char* __buffer = (char*)malloc(__length);
    fread((void*)__buffer, 1, __length, file);

    *buffer = __buffer;
    *length = __length;
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

void Shaders::useProgram() {
	glUseProgram(program);
}

void Shaders::deleteProgram() {
	glDeleteProgram(program);
}