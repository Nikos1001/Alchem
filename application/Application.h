
#pragma once
#include "../types.h"

namespace Alchem {

    class Application {

    public:
        void Run();
    protected:

        virtual void Start();
        virtual void Update(f32 delta);
        virtual bool ShouldContinue();

    };

}