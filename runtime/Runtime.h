
#pragma once

#include "../application/Application.h"
#include "../node/NodeTree.h"

namespace Alchem {

    class NodeTree;

    class Runtime : public Application {
    public:
        explicit Runtime(const string& projectPath);
        ui32 tex;
    private:
        void Start() override;
        void Update(f32 delta) override;
        bool ShouldContinue() override;
        string GetPath(const string& path);

        ptr<NodeTree> nodes;

        string projPath;
    };

}
