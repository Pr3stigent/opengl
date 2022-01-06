#pragma once

#include "GLFW/glfw3.h"
#include "GL/glew.h"
#include "string"
#include "sstream"
#include "iostream"
#include "fstream"
#include "cerrno"

std::string getFileContents();

class Shaders {
    private:
        GLuint program;
        std::string vertexFileName;
        std::string fragmentFileName;
    public:
        Shaders(std::string vertexFileName, std::string fragmentFileName);
        void activate();
        
};
