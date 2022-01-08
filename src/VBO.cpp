#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size): vertices(vertices), size(size) {
    glGenBuffers(1, &VertexBO);
    glBindBuffer(GL_ARRAY_BUFFER, VertexBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
 
void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, VertexBO);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
    glDeleteBuffers(1, &VertexBO);
}