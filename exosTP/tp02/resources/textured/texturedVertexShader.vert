#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec3 aBarycentric;

out vec3 ourColor;
out vec3 Barycentric;
out vec4 edgeColor;
out float lineThickness;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec4 edgeColorIn;
uniform float lineThicknessIn;


void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    ourColor = aColor;
    edgeColor = edgeColorIn;
    Barycentric = aBarycentric;
    lineThickness = lineThicknessIn;
}