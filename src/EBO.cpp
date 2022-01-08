#include "EBO.h"

EBO::EBO(GLuint* indices, GLsizeiptr size): indices(indices), size(size) {
    glGenBuffers(1, &VertexBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VertexBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}
 
void EBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VertexBO);
}

void EBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete() {
    glDeleteBuffers(1, &VertexBO);
}