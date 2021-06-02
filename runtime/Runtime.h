
#pragma once

#include "../application/Application.h"
#include "../resources/ResourceManager.h"
#include "../renderer/Texture.h"
#include "../resources/TextureManager.h"
#include "../node/Node.h"

namespace Alchem {

    class Node;

    class Runtime : public Application {
    public:
        explicit Runtime(const string& projectPath);
        string GetPath(const string& path);
        ptr<AlchemResource::TextureManager> textures;
    private:
        void Start() override;
        void Update(f32 delta) override;
        bool ShouldContinue() override;

        ptr<Node> root;

        string projPath;
    };

}
