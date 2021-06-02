
#include "SpriteNode.h"
#include "../../../renderer/Renderer2D.h"

namespace Alchem {

    void SpriteNode::Initialize(Runtime *rt) {
        Node2D::Initialize(rt);
        SetPath(path);
    }

    void SpriteNode::Render() {
        AlchemRenderer::Texture *tex = runtime->textures->Get(textureHandle);
        glm::mat4 transform = GetTransformation();
        if(tex != nullptr) {
            AlchemRenderer::Renderer2D::SubmitQuad(transform, tex->texId);
        }
    }

    void SpriteNode::SetPath(const string& newPath) {
        path = newPath;
        std::cout << path << std::endl;
        textureHandle = runtime->textures->GetHandle(path);
    }

    void SpriteNode::LoadFromJSON(json data) {
        Node2D::LoadFromJSON(data);
        path = data["spritePath"];
    }

}
