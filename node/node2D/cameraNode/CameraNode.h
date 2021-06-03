
#pragma once

#include "../Node2D.h"

namespace Alchem {

    class CameraNode  : public Node2D {
    public:
        CameraNode(Runtime* rt);
        void BeginRenderFrame() override;
        void LoadFromJSON(json data) override;
        f32 cameraSize = 5;
    };

}

