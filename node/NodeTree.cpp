
#include "NodeTree.h"
#include "node2D/spriteNode/SpriteNode.h"
#include "node2D/cameraNode/CameraNode.h"

#define NODE_TYPE(typeName) \
    if(type == #typeName) \
        nodes.push_back(std::make_unique<typeName>());

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
        runtime = rt;
    }

    void NodeTree::LoadJSONNode(const json& nodeData) {
        std::cout << nodeData << std::endl;
        string type = nodeData["type"];

        NODE_TYPE(Node);
        NODE_TYPE(Node2D);
        NODE_TYPE(SpriteNode);
        NODE_TYPE(CameraNode);

        Node *newNode = nodes.back().get();
        newNode->LoadFromJSON(nodeData);

        for(const auto& childData : nodeData["children"]) {
            LoadJSONNode(childData);
        }
    }
}
