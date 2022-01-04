#include "GLFW/glfw3.h"
#include "window.h"

Interface::Interface(int height, int width, std::string windowName) : height(height), width(width), windowName(windowName) {
     /* Initialize the library */
    glfwInit();

    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (window == NULL) {
        
    }
}

Interface::~Interface() {
    glfwTerminate();
}

bool Interface::shouldClose() {
    return glfwWindowShouldClose(window);
}