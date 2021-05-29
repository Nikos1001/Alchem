
#pragma once
#include "../utils.h"

namespace AlchemRenderer {

    struct BufferCollection {
        ui32 vertVBO, uvVBO;
        ui32 ebo;
        ui32 vao;
        ui32 tris;
    };

    ptr<BufferCollection> CreateBuffers(array<f32>& verts, array<f32>& uvs, array<ui32>& indices);
    void RenderBuffers(BufferCollection* buffers);
    void UpdateBuffers(BufferCollection* buffers, f32* verts, f32* uvs, ui32* indices, i32 numVerts, i32 numIndices);

}