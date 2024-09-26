#version 330 core
in vec3 ourColor;       // Couleur déterminée par la position (multicolore)
in vec3 Barycentric;
in float lineThickness;  // Contrôle l'épaisseur des lignes
in vec4 edgeColor;

out vec4 FragColor;

void main() {
    // Calculer la distance de la coordonnée barycentrique la plus petite
    float minBary = min(min(Barycentric.x, Barycentric.y), Barycentric.z);

    // Appliquer un seuil pour définir la zone de l'arête (ligne)
    float edgeFactor = step(lineThickness, minBary);


    // Utiliser `ourColor` pour les faces multicolores
    vec4 faceColor = vec4(ourColor, 1.0);  // Couleur multicolore basée sur la position

    // Mélange de la couleur des arêtes et de la couleur des faces en fonction de `edgeFactor`
    FragColor = mix(edgeColor, faceColor, edgeFactor);
}
