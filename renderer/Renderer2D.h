
#pragma once
#include <glm/ext.hpp>
#include "BufferUtils.h"

namespace AlchemRenderer {

    class Renderer2D {

    public:
        static void Initialize();
        static void SubmitQuad(glm::mat4& transform, ui32 texture);
        static void BeginScene();
        static void EndScene();
        static i32 drawCalls;

    private:

        static void RenderBatch();

        static ptr<BufferCollection> batchBuffer;
        static ui32 shaderProgram;

        static const i32 maxBufferedQuads = 20000;
        static const i32 textureSlots = 16;
        static f32 batchVerts[maxBufferedQuads * 4 * 3];
        static f32 batchUvs[maxBufferedQuads * 4 * 2];
        static ui32 batchIndices[maxBufferedQuads * 6];
        static f32 batchTextures[maxBufferedQuads * 4];
        static i32 usedTextures[textureSlots];
        static i32 renderedQuads;
        static f32 zOff;

    };

};

