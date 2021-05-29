
#pragma once
#include "../utils.h"
#include "BufferUtils.h"
#include <vector>
#include <GL/glew.h>

namespace AlchemRenderer {

    ptr<BufferCollection> CreateBuffers(array<f32>& verts, array<f32>& uvs, array<ui32>& indices) {
        ptr<BufferCollection> buffers = std::make_unique<BufferCollection>();

        glGenBuffers(1, &buffers->vertVBO);
        glGenBuffers(1, &buffers->uvVBO);
        glGenBuffers(1, &buffers->ebo);

        glGenVertexArrays(1, &buffers->vao);
        glBindVertexArray(buffers->vao);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, uvs.size() * sizeof(ui32), indices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, buffers->vertVBO);
        glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(f32), verts.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, buffers->uvVBO);
        glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(f32), uvs.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(f32), (void*)0);
        glEnableVertexAttribArray(1);

        buffers->tris = indices.size() / 3;

        return buffers;
    }

    void RenderBuffers(BufferCollection* buffers) {
        glBindVertexArray(buffers->vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers->ebo);
        glDrawElements(GL_TRIANGLES, buffers->tris * 3, GL_UNSIGNED_INT, 0);
    }

    void UpdateBuffers(BufferCollection* buffers, f32* verts, f32* uvs, ui32* indices, i32 numVerts, i32 numIndices) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(ui32), indices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, buffers->vertVBO);
        glBufferData(GL_ARRAY_BUFFER, 3 * numVerts * sizeof(f32), verts, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, buffers->uvVBO);
        glBufferData(GL_ARRAY_BUFFER, 2 * numVerts * sizeof(f32), uvs, GL_STATIC_DRAW);

        buffers->tris = numIndices / 3;

    }

}