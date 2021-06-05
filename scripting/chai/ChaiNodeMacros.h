
#pragma once
#include "../../lib/ChaiScript/include/chaiscript/chaiscript.hpp"

#define CHAI_NODE_DEFINITION_BEGIN(nodeType) \
    void AddNodeTypeToChai(chaiscript::ChaiScript& chai, nodeType* node) {

#define CHAI_NODE_DEFINITION_END() \
    }

#define CHAI_NODE_DEFINITION_ADD_METHOD(nodeType, methodName) \
    chai.add(chaiscript::fun(&nodeType::methodName, node), #methodName);

#define CHAI_NODE_DEFINITION_ADD_MEMBER(memberName) \
    chai.add_global(chaiscript::var(&node-> memberName), #memberName);

#define CHAI_NODE_DEFINITION_ADD_BASE(baseNodeType) \
    AddNodeTypeToChai(chai, (baseNodeType*)node);

namespace AlchemScripting::Chai {

    CHAI_NODE_DEFINITION_BEGIN(Alchem::Node)
        CHAI_NODE_DEFINITION_ADD_MEMBER(name)
    CHAI_NODE_DEFINITION_END()

    CHAI_NODE_DEFINITION_BEGIN(Alchem::Node2D)
        CHAI_NODE_DEFINITION_ADD_BASE(Alchem::Node)
        CHAI_NODE_DEFINITION_ADD_MEMBER(position)
        CHAI_NODE_DEFINITION_ADD_MEMBER(scale)
        CHAI_NODE_DEFINITION_ADD_MEMBER(rotation)
    CHAI_NODE_DEFINITION_END()

    CHAI_NODE_DEFINITION_BEGIN(Alchem::CameraNode)
        CHAI_NODE_DEFINITION_ADD_BASE(Alchem::Node2D)
    CHAI_NODE_DEFINITION_END()

    CHAI_NODE_DEFINITION_BEGIN(Alchem::SpriteNode)
        CHAI_NODE_DEFINITION_ADD_BASE(Alchem::Node2D)
    CHAI_NODE_DEFINITION_END()

}