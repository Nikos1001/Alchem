
#include "NodeTree.h"
#include "node2D/spriteNode/SpriteNode.h"

namespace Alchem {

    void NodeTree::Update(f32 delta) {

        for(auto& node : nodes) {
            node->BeginFrame();
        }
        for(auto& node : nodes) {
            node->Update(delta);
        }
        for(auto& node : nodes) {
            node->EndFrame();
        }

        for(auto& node : nodes) {
            node->BeginRenderFrame();
        }
        for(auto& node : nodes) {
            node->Render();
        }
        for(auto& node : nodes) {
            node->EndRenderFrame();
        }

    }

    NodeTree::NodeTree(Runtime* rt) {
        nodes.push_back(std::make_unique<SpriteNode>());
        nodes[0]->Initialize(rt);
    }
}
