#include "iostream"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window.h"
#include "shaders.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"

int main() {
   
    Interface newInterface = Interface(800, 600, "Hello World!");
    gladLoadGL();
    glViewport(0, 0, 800, 600);

    Shaders shader = Shaders("default.vert", "default.frag");
    VAO newVAO = VAO();
    newVAO.Bind();

    VBO newVBO = VBO(vertices, sizeof(vertices));
    EBO newEBO = EBO(indices, sizeof(indices));

    newVAO.LinkVBO(newVBO, 0);
    newVAO.Unbind();
    newVBO.Unbind();
    newEBO.Unbind();

    while (!newInterface.shouldClose()) {
        shader.useProgram();
        newVAO.Bind();

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        newInterface.swapBuffers();
        glfwPollEvents();
    }

    newVAO.Delete();
    newVBO.Delete();
    newEBO.Delete();
    shader.deleteProgram();
    newInterface.terminateWindow(true);
    return 0;
}