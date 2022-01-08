#pragma once

#include "glad/glad.h"

class VBO {
    private:
        GLuint VertexBO;
        GLfloat* vertices;
        GLsizeiptr size;
    public:
        VBO(GLfloat* vertices, GLsizeiptr size);
        void Bind();
        void Unbind();
        void Delete();
};