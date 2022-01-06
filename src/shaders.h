#pragma once

#include "GLFW/glfw3.h"
#include "string"

std::string getFileContents();

class Shaders {
    private:
        GLuint program;

    public:
        Shaders();
        ~Shaders();
        void Activate();
        void Delete();
        
};
