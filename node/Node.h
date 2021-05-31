
#pragma once

#include "../types.h"
#include "../runtime/Runtime.h"

namespace Alchem {

    class Runtime;

    class Node {
    public:
        virtual void Initialize(Runtime* runtime);

        virtual void BeginFrame();
        virtual void Update(f32 delta);
        virtual void EndFrame();

        virtual void BeginRenderFrame();
        virtual void Render();
        virtual void EndRenderFrame();

    protected:
        Runtime* runtime;
    };

}

