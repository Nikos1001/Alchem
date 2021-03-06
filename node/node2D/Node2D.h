
#pragma once

#include <glm/ext.hpp>
#include "../Node.h"

namespace Alchem {

    class Node2D : public Node {
    public:
        Node2D(Runtime* rt);

        void LoadFromJSON(json data) override;
        void Initialize() override;

        glm::mat4 GetTransformation();

        void SetRotation(float newRotation);

        glm::vec2 position = glm::vec2(0, 0);
        glm::vec2 scale = glm::vec2(1, 1);
        f32 rotation = 0;
    };

}