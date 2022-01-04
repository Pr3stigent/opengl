#include "GLFW/glfw3.h"
#include "window.h"

int main() {
    const int HEIGHT = 800;
    const int WIDTH = 600;
    const std::string WINDOWNAME = "Hello World!";

    Interface interface {HEIGHT, WIDTH, WINDOWNAME};
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!interface.shouldClose())
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    interface.~Interface();
    return 0;
}