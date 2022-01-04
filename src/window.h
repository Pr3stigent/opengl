#pragma once

#include "GLFW/glfw3.h"
#include "string"

class Interface {
    public:
        Interface(int height, int width, std::string windowName);
        ~Interface();

        GLFWwindow* window;
};