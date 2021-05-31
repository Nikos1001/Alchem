
#pragma once

#include <glm/ext.hpp>
#include "../Node.h"

namespace Alchem {

    class Node2D : public Node {
    public:
        virtual void Initialize(Runtime* rt);

        virtual void BeginFrame();
        virtual void Update(f32 delta);
        virtual void EndFrame();

        virtual void BeginRenderFrame();
        virtual void Render();
        virtual void EndRenderFrame();

        glm::vec2 position, scale;
        f32 rotation;
    };

}