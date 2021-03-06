#include "iostream"
#include "GLFW/glfw3.h"
#include "window.h"

Interface::Interface(int height, int width, std::string windowName) : height(height), width(width), windowName(windowName) {
    Interface::initiateWindow(height, width, windowName);
}

Interface::~Interface() {
    glfwTerminate();
}

int Interface::initiateWindow(int height, int width, std::string windowName) {
    if(!glfwInit()){
        std::cout << "GLFW was unable to be initialised." << std::endl;
        return -1;
    };

    window = glfwCreateWindow(height, width, windowName.c_str(), NULL, NULL);
    if (window == NULL) {
        std::cout << "Window was unable to be created." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    return 1;
}

void Interface::terminateWindow(bool terminateGLFW) {
    glfwDestroyWindow(window);

    if (terminateGLFW) {
        glfwTerminate();
    }
}

bool Interface::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Interface::swapBuffers() {
    glfwSwapBuffers(window);
}