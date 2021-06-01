
#pragma once

#include "../Node2D.h"

namespace Alchem {

    class CameraNode  : public Node2D {
    public:
        CameraNode();
        void BeginRenderFrame() override;
        f32 cameraSize = 5;
    };

}

