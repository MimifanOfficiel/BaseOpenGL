#version 330 core

in vec3 FragPos;   // Position du fragment en espace monde (envoyée par le vertex shader)
in vec3 Normal;    // Normale interpolée

out vec4 FragColor;  // Couleur de sortie du fragment

uniform vec3 lightPos;  // Position de la lumière en espace monde
uniform vec3 viewPos;   // Position de la caméra (vue)
uniform vec3 lightColor;  // Couleur de la lumière
uniform vec3 objectColor; // Couleur de l'objet

void main() {
    // Normalisation de la normale interpolée
    vec3 norm = normalize(Normal);

    // Calcul du vecteur lumière (direction de la lumière vers le fragment)
    vec3 lightDir = normalize(lightPos - FragPos);

    // Éclairage diffus (Lambertian)
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Calcul de la réflexion spéculaire (Phong)
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = 0.5 * spec * lightColor; // Le facteur de brillance est arbitraire

    // Couleur finale (diffus + spéculaire) multipliée par la couleur de l'objet
    vec3 result = (diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}
