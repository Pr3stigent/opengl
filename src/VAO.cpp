#include "VAO.h"

VAO::VAO() {
   glGenVertexArrays(1, &VertexBO);
}

void VAO::LinkVBO(VBO VBO, GLuint layout) {
    VBO.Bind();
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

void VAO::Bind() {
    glBindVertexArray(VertexBO);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::Delete() {
    glDeleteVertexArrays(1, &VertexBO);
}