
#pragma once

#include "../Node.h"
#include "../../lib/ChaiScript/include/chaiscript/chaiscript.hpp"

namespace Alchem {

    class ChaiScriptNode : public Node {
    public:
        explicit ChaiScriptNode(Runtime* rt);
        void Initialize() override;

        void BeginFrame() override;
        void Update(f32 delta) override;
        void EndFrame() override;

        void BeginRenderFrame() override;
        void Render() override;
        void EndRenderFrame() override;
    private:
        void LoadFromJSON(json data) override;
        string scriptPath;
        chaiscript::ChaiScript chaiscript;
        ptr<Node> baseNode;
        json loadData;

    };

}