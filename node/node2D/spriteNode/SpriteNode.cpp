
#include "SpriteNode.h"
#include "../../../renderer/Renderer2D.h"

namespace Alchem {

    SpriteNode::SpriteNode(Runtime* rt) : Node2D(rt) {

    }

    void SpriteNode::Initialize() {
        Node2D::Initialize();
        SetPath(path);
    }

    void SpriteNode::Render() {
        Node2D::Render();
        AlchemRenderer::Texture *tex = runtime->textures->Get(textureHandle);
        glm::mat4 transform = GetTransformation();
        if(tex != nullptr) {
            AlchemRenderer::Renderer2D::SubmitQuad(transform, tex->texId);
        }
    }

    void SpriteNode::SetPath(const string& newPath) {
        path = newPath;
        textureHandle = runtime->textures->GetHandle(path);
    }

    void SpriteNode::LoadFromJSON(json data) {
        Node2D::LoadFromJSON(data);
        path = data["spritePath"];
    }

}
