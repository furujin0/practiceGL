#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
out vec3 ourColor;

uniform float offsetX;
uniform float offsetY;

void main(){
    gl_Position = vec4(aPos.x + offsetX, aPos.y + offsetY, aPos.z, 1.0);
    ourColor = vec3(gl_Position.x, gl_Position.y, aPos.z);
}