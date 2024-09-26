#version 330 core

in vec3 vertexColor; // Couleur transmise par le vertex shader

out vec4 FragColor;

void main() {
    // Appliquer la couleur interpolée
    FragColor = vec4(vertexColor, 1.0);
    // FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
