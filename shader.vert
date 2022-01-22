#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;
out vec3 ourColor;
out vec2 TexCoord;
uniform float offsetX;
uniform float offsetY;
uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main(){
    gl_Position = projMat * viewMat * modelMat * vec4(aPos.x + offsetX, aPos.y + offsetY, aPos.z, 1.0);
    ourColor = aColor;
    TexCoord = aTexCoord;
}