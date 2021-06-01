
#include "Node2D.h"

namespace Alchem {

    Node2D::Node2D() {
        scale = glm::vec2(1, 1);
    }

    void Node2D::Initialize(Runtime* rt) {
        Node::Initialize(rt);
    }

    void Node2D::BeginFrame() {
        Node::BeginFrame();
    }

    void Node2D::Update(f32 delta) {
        Node::Update(delta);
    }

    void Node2D::EndFrame() {
        Node::EndFrame();
    }

    void Node2D::BeginRenderFrame() {
        Node::BeginRenderFrame();
    }

    void Node2D::Render() {
        Node::Render();
    }

    void Node2D::EndRenderFrame() {
        Node::EndRenderFrame();
    }

    glm::mat4 Node2D::GetTransformation() {
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(position.x, position.y, 0));
        transform = glm::rotate(transform, rotation, glm::vec3(0, 0, 1));
        transform = glm::scale(transform, glm::vec3(scale.x, scale.y, 1));
        return transform;
    }

}
