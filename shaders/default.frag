#version 140
#extension GL_ARB_explicit_attribute_location: require
#extension GL_ARB_explicit_uniform_location: require

out vec4 FragColour;

void main() {
    FragColour = vec4(aPos.X, aPos.y, aPos.z, 1.0);
}