
#include "SpriteNode.h"
#include "../../../renderer/Renderer2D.h"

namespace Alchem {

    void SpriteNode::Render() {
        glm::mat4 trans = glm::mat4(1.0f);
        AlchemRenderer::Renderer2D::SubmitQuad(trans, runtime->tex);
    }

}
