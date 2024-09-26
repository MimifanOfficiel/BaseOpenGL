#version 330 core

layout (location = 0) in vec3 aPos;     // Position du sommet
layout (location = 1) in vec3 aNormal;  // Normale du sommet

out vec3 FragPos;   // Position du fragment (en espace monde)
out vec3 Normal;    // Normale interpolée

uniform mat4 model;   // Matrice modèle (transformations)
uniform mat4 view;    // Matrice vue (caméra)
uniform mat4 projection; // Matrice projection

void main() {
    // Transforme la position du sommet en espace monde et la passe au fragment shader
    FragPos = vec3(model * vec4(aPos, 1.0));
    
    // Transforme la normale avec la matrice modèle pour obtenir une normale en espace monde
    Normal = mat3(transpose(inverse(model))) * aNormal;
    
    // Projection, vue et modèle pour la position du sommet final
    gl_Position = projection * view * vec4(FragPos, 1.0);
}
