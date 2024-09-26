#version 330 core

layout(location = 0) in vec3 aPos;

out vec4 vertexColor; // Couleur à passer au fragment shader

uniform vec4 color; // Couleur personnalisée envoyée depuis C++

void main() {
    gl_Position = vec4(aPos, 1.0);
    vertexColor = color; // Passer la couleur personnalisée au fragment shader
}
