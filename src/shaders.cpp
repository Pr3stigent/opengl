#include "shaders.h"

std::vector<char> getFileContents(const std::string& filepath) {
  std::ifstream file{filepath, std::ios::ate | std::ios::binary};

  if (!file.is_open()) {
    throw std::runtime_error("failed to open file: " + filepath);
  }

  size_t fileSize = static_cast<size_t>(file.tellg());
  std::vector<char> buffer(fileSize);

  file.seekg(0);
  file.read(buffer.data(), fileSize);

  file.close();
  return buffer;
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