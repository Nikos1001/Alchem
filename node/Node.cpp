
#include "Node.h"
#include "node2D/Node2D.h"
#include "node2D/cameraNode/CameraNode.h"
#include "node2D/spriteNode/SpriteNode.h"
#include "script/ChaiScriptNode.h"

namespace Alchem {

    Node::Node(Runtime* rt) {
        runtime = rt;
        initialized = false;
    }

    void Alchem::Node::Initialize() {
        initialized = true;
    }

    void Node::BeginFrame() {
        if(!initialized)
            Initialize();
        for(ptr<Node>& child : children)
            child->BeginFrame();
    }

    void Node::Update(f32 delta) {
        for(ptr<Node>& child : children)
            child->Update(delta);
    }

    void Node::EndFrame() {
        for(ptr<Node>& child : children)
            child->EndFrame();
    }

    void Node::BeginRenderFrame() {
        for(ptr<Node>& child : children)
            child->BeginRenderFrame();
    }

    void Node::Render() {
        for(ptr<Node>& child : children)
            child->Render();
    }

    void Node::EndRenderFrame() {
        for(ptr<Node>& child : children)
            child->EndRenderFrame();
    }

    void Node::LoadFromJSON(json data) {
        for(const auto& childData : data["children"]) {
            children.push_back(LoadNodeFromJSON(childData, runtime));
            children.back()->parent = this;
        }
    }

#define NODE_TYPE(nodeType) \
    if(type == #nodeType) \
        node = std::make_unique<nodeType>(rt);

    ptr<Node> LoadNodeFromJSON(json data, Runtime* rt) {
        string type = data["type"];
        ptr<Node> node;
        NODE_TYPE(Node);
        NODE_TYPE(Node2D);
        NODE_TYPE(CameraNode);
        NODE_TYPE(SpriteNode);
        NODE_TYPE(ChaiScriptNode);
        node->LoadFromJSON(data);
        return node;
    }

}
