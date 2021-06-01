
#include "SpriteNode.h"
#include "../../../renderer/Renderer2D.h"

namespace Alchem {

    void SpriteNode::Render() {
        glm::mat4 transform = glm::mat4(1.0f);
        AlchemRenderer::Texture *tex = runtime->textures->Get(textureHandle);
        if(tex != nullptr) {
            AlchemRenderer::Renderer2D::SubmitQuad(transform, tex->texId);
        }
    }

    void SpriteNode::SetPath(const string& newPath) {
        path = newPath;
        textureHandle = runtime->textures->GetHandle(path);
    }

    void SpriteNode::Initialize(Runtime *rt) {
        Node2D::Initialize(rt);
        SetPath("logo.png");
    }

}
