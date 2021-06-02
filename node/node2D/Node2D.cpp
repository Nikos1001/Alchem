
#include "Node2D.h"

namespace Alchem {

    Node2D::Node2D() {
        scale = glm::vec2(1, 1);
    }

    glm::mat4 Node2D::GetTransformation() {
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(position.x, position.y, 0));
        transform = glm::rotate(transform, rotation, glm::vec3(0, 0, 1));
        transform = glm::scale(transform, glm::vec3(scale.x, scale.y, 1));
        return transform;
    }

    void Node2D::LoadFromJSON(json data) {
        Node::LoadFromJSON(data);
        position = glm::vec2(data["position"][0], data["position"][1]);
        scale = glm::vec2(data["scale"][0], data["scale"][1]);
        rotation = data["rotation"];
    }

}
