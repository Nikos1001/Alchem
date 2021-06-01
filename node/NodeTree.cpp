
#include "NodeTree.h"
#include "node2D/spriteNode/SpriteNode.h"
#include "node2D/cameraNode/CameraNode.h"

namespace Alchem {

    void NodeTree::Update(f32 delta) {
        for(auto& node : nodes) {
            if(!node->initialized) {
                node->initialized = true;
                node->Initialize(runtime);
            }
        }

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
        nodes.push_back(std::make_unique<CameraNode>());
        runtime = rt;
    }
}
