
#pragma once

#include "../types.h"
#include "../runtime/Runtime.h"

namespace Alchem {

    class Runtime;

    class Node {
        friend class ChaiScriptNode;

    public:
        Node(Runtime* runtime);
        virtual void Initialize();

        virtual void BeginFrame();
        virtual void Update(f32 delta);
        virtual void EndFrame();

        virtual void BeginRenderFrame();
        virtual void Render();
        virtual void EndRenderFrame();

        virtual void LoadFromJSON(json data);

    protected:
        Runtime* runtime;
        array<ptr<Node>> children;
        Node* parent = nullptr;
    private:
        bool initialized;
    };

    ptr<Node> LoadNodeFromJSON(json data, Runtime* rt);

}

