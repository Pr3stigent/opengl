#include "GLFW/glfw3.h"
#include "window.h"

int main() {
    const int HEIGHT = 800;
    const int WIDTH = 600;
    const std::string WINDOWNAME = "Hello World!";

    Interface interface {HEIGHT, WIDTH, WINDOWNAME};

    while (!interface.shouldClose()) {
        glfwPollEvents();
    }

    interface.terminateWindow(true);
    return 0;
}