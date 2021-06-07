
#include "ChaiScriptNode.h"
#include "../node2D/Node2D.h"
#include "../node2D/cameraNode/CameraNode.h"
#include "../node2D/spriteNode/SpriteNode.h"
#include "../../scripting/chai/ChaiNodeMacros.h"
#include "../../input/Input.h"
#include "../../utils/Random.h"
#include "../../lib/chaiscript-glm/chaislcript_glm.hpp"

#define CHAISCRIPT_NODE_TYPE(nodeType) \
    if(baseNodeType == #nodeType) { \
        baseNode = std::make_unique<nodeType>(runtime); \
        AlchemScripting::Chai::AddNodeTypeToChai(chaiscript, (nodeType*)(baseNode.get())); \
    }

namespace Alchem {

    ChaiScriptNode::ChaiScriptNode(Runtime *rt) : Node(rt) {

    }

    void ChaiScriptNode::LoadFromJSON(json data) {
        Node::LoadFromJSON(data);
        scriptPath = data["scriptPath"];
        loadData = data;
        children.clear();
    }

    void ChaiScriptNode::Initialize() {
        Node::Initialize();
        chaiscript.add(get_glm_module());
        chaiscript.eval_file(runtime->GetPath(scriptPath));
        string baseNodeType = chaiscript.eval<string>("baseNode");
        CHAISCRIPT_NODE_TYPE(Node);
        CHAISCRIPT_NODE_TYPE(Node2D);
        CHAISCRIPT_NODE_TYPE(CameraNode);
        CHAISCRIPT_NODE_TYPE(SpriteNode);
        baseNode->parent = parent;
        baseNode->LoadFromJSON(loadData);
        baseNode->Initialize();

        chaiscript.add(chaiscript::fun(&AlchemInput::Input::KeyPressed), "KeyPressed");
        chaiscript.add(chaiscript::fun(&AlchemUtils::Random::Val), "Random");

        try {
            chaiscript("Initialize();");
        } catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void ChaiScriptNode::BeginFrame() {
        Node::BeginFrame();
        baseNode->BeginFrame();
    }

    void ChaiScriptNode::Update(f32 delta) {
        Node::Update(delta);
        baseNode->Update(delta);
        try {
            chaiscript("Update(" + std::to_string(delta) + "f);");
        } catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
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