
#include "SpriteNode.h"
#include "../../../renderer/Renderer2D.h"

namespace Alchem {

    void SpriteNode::Initialize(Runtime *rt) {
        Node2D::Initialize(rt);
        SetPath("logo.png");
        position = glm::vec2(2, 1);
        scale = glm::vec2(0.815, 1);
        rotation = 1.32344;
    }

    void SpriteNode::Render() {
        AlchemRenderer::Texture *tex = runtime->textures->Get(textureHandle);
        glm::mat4 transform = GetTransformation();
        if(tex != nullptr) {
            AlchemRenderer::Renderer2D::SubmitQuad(transform, tex->texId);
        }
        rotation += 0.01;
    }

    void SpriteNode::SetPath(const string& newPath) {
        path = newPath;
        textureHandle = runtime->textures->GetHandle(path);
    }

}
