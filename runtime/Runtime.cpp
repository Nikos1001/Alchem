
#include "Runtime.h"
#include "../renderer/Window.h"
#include "../renderer/Renderer2D.h"
#include "../renderer/TextureUtils.h"

#pragma once

namespace Alchem {

    Runtime::Runtime(const string& projectPath) {
        projPath = projectPath;
        nodes = std::make_unique<NodeTree>(this);
    }

    void Runtime::Start() {
        AlchemRenderer::Window::Open();
        AlchemRenderer::Renderer2D::Initialize();
    }

    void Alchem::Runtime::Update(f32 delta) {

        AlchemRenderer::Renderer2D::BeginScene();

//        glm::mat4 transform = glm::mat4(1.0f);
//        ui32 texture = AlchemRenderer::LoadTexture(GetPath("logo.png"));
//        AlchemRenderer::Renderer2D::SubmitQuad(transform, texture);
        tex = AlchemRenderer::LoadTexture(GetPath("logo.png"));

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