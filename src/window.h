#pragma once

#include "GLFW/glfw3.h"
#include "string"

class Interface {
    public:
        int height, width;
        std::string windowName;
        GLFWwindow* window;

        Interface(int height, int width, std::string windowName);
        ~Interface();
        bool shouldClose();
        
};