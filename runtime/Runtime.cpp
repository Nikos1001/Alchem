
#include <fstream>
#include "Runtime.h"
#include "../renderer/Window.h"
#include "../renderer/Renderer2D.h"

namespace Alchem {

    Runtime::Runtime(const string& projectPath) {
        projPath = projectPath;
        textures = std::make_unique<AlchemResource::TextureManager>(this);
        nodes = std::make_unique<NodeTree>(this);

        std::ifstream nodeFile(GetPath("main.alcmNode"));
        json nodeData;
        nodeFile >> nodeData;
        nodes->LoadJSONNode(nodeData);
    }

    void Runtime::Start() {
        AlchemRenderer::Window::Open();
        AlchemRenderer::Renderer2D::Initialize();
    }

    void Alchem::Runtime::Update(f32 delta) {

        AlchemRenderer::Renderer2D::BeginScene();

        nodes->Update(delta);

        AlchemRenderer::Renderer2D::EndScene();

        AlchemRenderer::Window::EndFrame();
    }

    bool Runtime::ShouldContinue() {
        return !AlchemRenderer::Window::ShouldClose();
    }

    string Runtime::GetPath(const string &path) {
        return projPath + path;
    }

}