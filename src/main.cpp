#include "iostream"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window.h"
#include "shaders.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"

GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};

// Indices for vertices order
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};

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
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
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