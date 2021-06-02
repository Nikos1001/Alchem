
#pragma once

#include "../Node2D.h"
#include "../../NodeTree.h"

namespace Alchem {

    class SpriteNode : public Node2D {

    public:
        void Initialize(Runtime* rt) override;
        void Render() override;
        void SetPath(const string& newPath);
        void LoadFromJSON(json data) override;
    private:
        string path;
        AlchemResource::ResourceHandle textureHandle;
    };

}