
#include <GL/glew.h>
#include "../utils.h"
#include "ShaderUtils.h"
#include <string>
#include <fstream>
#include "BufferUtils.h"
#include "glm/ext.hpp"
#include "Renderer2D.h"

#pragma once

f32 verts[4][3] = {
        {0.5f,  0.5f, 0.0f},
        {0.5f, -0.5f, 0.0f},
        {-0.5f, -0.5f, 0.0f},
        {-0.5f,  0.5f, 0.0f}
};

f32 uvs[8] = {
        1, 1,
        1, 0,
        0, 0,
        0, 1,
};

namespace AlchemRenderer {

    void Renderer2D::SubmitQuad(glm::mat4& transform) {
        zOff += 0.01;
        for(i32 i = 0; i < 4; i ++) {
            glm::vec4 vert = glm::vec4(verts[i][0], verts[i][1], verts[i][2] - zOff, 1);
            vert = transform * vert;
            batchVerts[renderedQuads * 4 * 3 + 3 * i] = vert.x;
            batchVerts[renderedQuads * 4 * 3 + 3 * i + 1] = vert.y;
            batchVerts[renderedQuads * 4 * 3 + 3 * i + 2] = vert.z;
        }
        for(i32 i = 0; i < 8; i++)
            batchUvs[renderedQuads * 4 * 2 + i] = uvs[i];

        batchIndices[renderedQuads * 6] = renderedQuads * 4 + 2;
        batchIndices[renderedQuads * 6 + 1] = renderedQuads * 4;
        batchIndices[renderedQuads * 6 + 2] = renderedQuads * 4 + 1;

        batchIndices[renderedQuads * 6 + 3] = renderedQuads * 4;
        batchIndices[renderedQuads * 6 + 4] = renderedQuads * 4 + 3;
        batchIndices[renderedQuads * 6 + 5] = renderedQuads * 4 + 2;

        renderedQuads++;
        if(renderedQuads >= maxBufferedQuads) {
            RenderBatch();
            renderedQuads = 0;
        }
    }

    void Renderer2D::Initialize() {
        std::ifstream f("basic.frag");
        string fragSource((std::istreambuf_iterator<char>(f)),
                          std::istreambuf_iterator<char>());

        std::ifstream v("basic.vert");
        string vertSource((std::istreambuf_iterator<char>(v)),
                          std::istreambuf_iterator<char>());

        ui32 vertexShader = CreateShader(vertSource, GL_VERTEX_SHADER);

        ui32 fragmentShader = CreateShader(fragSource, GL_FRAGMENT_SHADER);

        shaderProgram = CreateProgram(vertexShader, fragmentShader);

        array<f32> temp;
        array<ui32> temp2;
        batchBuffer = CreateBuffers(temp, temp, temp2);
    }

    ui32 Renderer2D::shaderProgram = 0;
    ptr<BufferCollection> Renderer2D::batchBuffer = nullptr;
    f32 Renderer2D::zOff = 0;
    i32 Renderer2D::renderedQuads = 0;
    f32 Renderer2D::batchVerts[maxBufferedQuads * 4 * 3];
    f32 Renderer2D::batchUvs[maxBufferedQuads * 4 * 2];
    ui32 Renderer2D::batchIndices[maxBufferedQuads * 6];

    void Renderer2D::BeginScene() {
        renderedQuads = 0;
        zOff = 0;
    }

    void Renderer2D::EndScene() {
        if(renderedQuads > 0)
            RenderBatch();
    }

    void Renderer2D::RenderBatch() {
        UpdateBuffers(batchBuffer.get(), &batchVerts[0], &batchUvs[0], &batchIndices[0], renderedQuads * 4, renderedQuads * 6);
        BindProgram(shaderProgram);
        glm::mat4 mat(1.0f);
        Mat4Uniform(shaderProgram, "uTransform", mat);
        RenderBuffers(batchBuffer.get());
    }
}