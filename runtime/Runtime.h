
#pragma once

#include "../application/Application.h"
#include "../node/NodeTree.h"
#include "../resources/ResourceManager.h"
#include "../renderer/Texture.h"
#include "../resources/TextureManager.h"

namespace Alchem {

    class NodeTree;

    class Runtime : public Application {
    public:
        explicit Runtime(const string& projectPath);
        string GetPath(const string& path);
        ptr<AlchemResource::TextureManager> textures;
    private:
        void Start() override;
        void Update(f32 delta) override;
        bool ShouldContinue() override;

        ptr<NodeTree> nodes;

        string projPath;
    };

}
