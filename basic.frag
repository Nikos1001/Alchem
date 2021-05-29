#version 330 core
out vec4 FragColor;
in vec2 uv;
void main() {
    float val = uv.y * 0.025f + 0.15f;
    FragColor = vec4(uv.x, uv.y, 0.2f, 1.0f);
}
