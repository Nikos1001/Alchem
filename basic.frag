#version 330 core

out vec4 frag;
in vec2 uv;
uniform sampler2D uAlbedo[16];
in float textureIdx;

void main() {
    float val = uv.y * 0.025f + 0.15f;
    int texIdx = 0;
    for(int i = 0; i < 16; i++) {
        if(textureIdx >= i)
            texIdx = i;
    }
    vec4 color = texture(uAlbedo[texIdx], uv);
    if(color.a < 0.99f)
        discard;
    frag = color;
}
