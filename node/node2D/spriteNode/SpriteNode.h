
#pragma once

#include "../Node2D.h"
namespace Alchem {

    class SpriteNode : public Node2D {

    public:
        SpriteNode(Runtime* rt);
        void Initialize() override;
        void Render() override;
        void SetPath(const string& newPath);
        void LoadFromJSON(json data) override;
    private:
        string path;
        AlchemResource::ResourceHandle textureHandle;
    };

}