#pragma once

#include "glad/glad.h"

class EBO {
    private:
        GLuint VertexBO;
        GLuint* indices;
        GLsizeiptr size;
    public:
        EBO(GLuint* indices, GLsizeiptr size);
        void Bind();
        void Unbind();
        void Delete();
};