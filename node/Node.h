
#pragma once

#include "../types.h"
#include "../runtime/Runtime.h"

namespace Alchem {

    class Runtime;

    class Node {
    friend class NodeTree;

    public:
        virtual void Initialize(Runtime* runtime);

        virtual void BeginFrame();
        virtual void Update(f32 delta);
        virtual void EndFrame();

        virtual void BeginRenderFrame();
        virtual void Render();
        virtual void EndRenderFrame();

        virtual void LoadFromJSON(json data);

    protected:
        Runtime* runtime;
        bool initialized;
    };

}

