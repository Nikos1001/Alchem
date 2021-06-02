
#pragma once

#include "Node.h"
#include "../types.h"

namespace Alchem {

    class Node;
    class Runtime;

    class NodeTree {
    public:
        NodeTree(Runtime* rt);
        void Update(f32 delta);
        void LoadJSONNode(const json& nodeData);
    private:
        array<ptr<Node>> nodes;
        Runtime* runtime;
    };

}