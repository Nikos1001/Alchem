
#pragma once
#include "../types.h"

namespace AlchemRenderer {

    struct BufferCollection {
        ui32 vertVBO, uvVBO, texVBO;
        ui32 ebo;
        ui32 vao;
        ui32 tris;
    };

    ptr<BufferCollection> CreateBuffers(array<f32>& verts, array<f32>& uvs, array<f32>& tex, array<ui32>& indices);
    void RenderBuffers(BufferCollection* buffers);
    void UpdateBuffers(BufferCollection* buffers, f32* verts, f32* uvs, f32* tex, ui32* indices, i32 numVerts, i32 numIndices);

}