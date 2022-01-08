#pragma once

#include "glad/glad.h"
#include "VBO.h"

class VAO {
    private:
        GLuint VertexBO;
    
    public:
        VAO();
        void LinkVBO(VBO VBO, GLuint layout);
        void Bind();
        void Unbind();
        void Delete();
};