
#pragma once

#include "../Node2D.h"
#include "../../NodeTree.h"

namespace Alchem {

    class SpriteNode : public Node2D {

    public:
        void Render() override;
    };

}