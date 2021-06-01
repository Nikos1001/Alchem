
#pragma once

#include <glm/ext.hpp>
#include "../Node.h"

namespace Alchem {

    class Node2D : public Node {
    public:
        Node2D();

        virtual void Initialize(Runtime* rt);

        virtual void BeginFrame();
        virtual void Update(f32 delta);
        virtual void EndFrame();

        virtual void BeginRenderFrame();
        virtual void Render();
        virtual void EndRenderFrame();

        glm::mat4 GetTransformation();

        glm::vec2 position = glm::vec2(0, 0), scale = glm::vec2(1, 1);
        f32 rotation = 0;
    };

}