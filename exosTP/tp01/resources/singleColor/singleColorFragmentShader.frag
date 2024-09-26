#version 330 core

in vec4 vertexColor; // Couleur reçue du vertex shader

out vec4 FragColor;

void main() {
    FragColor = vertexColor; // Utiliser la couleur reçue du vertex shader
}
