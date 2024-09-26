#version 330 core

layout(location = 0) in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 vertexColor; 

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0);


    vertexColor = vec3((position.x + 1.0) / 2.0, (position.y + 1.0) / 2.0, (position.z + 1.0) / 2.0);
}
