#include "GLFW/glfw3.h"
#include "window.h"

int main() {
    Interface newInterface = Interface(800, 600, "Hello World!");

    while (!newInterface.shouldClose()) {
        glfwPollEvents();
    }

    newInterface.terminateWindow(true);
    return 0;
}