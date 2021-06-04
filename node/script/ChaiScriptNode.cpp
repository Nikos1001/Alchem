
#include "ChaiScriptNode.h"
#include "../node2D/Node2D.h"
#include "../node2D/cameraNode/CameraNode.h"
#include "../node2D/spriteNode/SpriteNode.h"

#define CHAISCRIPT_NODE_TYPE(nodeType) \
    if(baseNodeType == #nodeType) \
        baseNode = std::make_unique<nodeType>(runtime);

namespace Alchem {

    ChaiScriptNode::ChaiScriptNode(Runtime *rt) : Node(rt) {

    }

    void ChaiScriptNode::LoadFromJSON(json data) {
        Node::LoadFromJSON(data);
        scriptPath = data["scriptPath"];
        loadData = data;
    }

    void ChaiScriptNode::Initialize() {
        Node::Initialize();
        chaiscript.eval_file(runtime->GetPath(scriptPath));
        string baseNodeType = chaiscript.eval<string>("baseNode");
        CHAISCRIPT_NODE_TYPE(Node);
        CHAISCRIPT_NODE_TYPE(Node2D);
        CHAISCRIPT_NODE_TYPE(CameraNode);
        CHAISCRIPT_NODE_TYPE(SpriteNode);
        baseNode->parent = parent;
        baseNode->LoadFromJSON(loadData);
        baseNode->Initialize();
    }

    void ChaiScriptNode::BeginFrame() {
        Node::BeginFrame();
        baseNode->BeginFrame();
    }

    void ChaiScriptNode::Update(f32 delta) {
        Node::Update(delta);
        baseNode->Update(delta);
    }

    void ChaiScriptNode::EndFrame() {
        Node::EndFrame();
        baseNode->EndFrame();
    }

    void ChaiScriptNode::BeginRenderFrame() {
        Node::BeginRenderFrame();
        baseNode->BeginRenderFrame();
    }

    void ChaiScriptNode::Render() {
        Node::Render();
        baseNode->Render();
    }

    void ChaiScriptNode::EndRenderFrame() {
        Node::EndRenderFrame();
        baseNode->EndRenderFrame();
    }

}