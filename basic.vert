#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUv;
layout (location = 2) in float aTexture;

uniform mat4 uTransform;
out vec2 uv;
out float textureIdx;

void main() {
    gl_Position = uTransform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    uv = aUv;
    textureIdx = aTexture;
}