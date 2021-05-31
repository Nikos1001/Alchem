#include <iostream>
#include <chrono>
#include <glm/ext.hpp>
#include "types.h"
#include "renderer/Renderer2D.h"
#include "renderer/TextureUtils.h"
#include "renderer/Window.h"

int main() {
    AlchemRenderer::Window::Open();

    glm::mat4 projection = glm::ortho<f32>(-4, 4, -3, 3, -100, 100);
    glm::mat4 transform = projection;

    transform = glm::translate(transform, glm::vec3(2, 0, 0));

    transform = glm::scale(transform, glm::vec3(1.63, 2, 1));

    ui32 logo = AlchemRenderer::LoadTexture("logo.png");
    ui32 face = AlchemRenderer::LoadTexture("logo2.png");

    AlchemRenderer::Renderer2D::Initialize();

    auto prevFrameTime = std::chrono::high_resolution_clock::now();

    f32 fps = 0;
    f32 timer = 0;
    while(!AlchemRenderer::Window::ShouldClose())
    {
        AlchemRenderer::Renderer2D::BeginScene();

        auto currTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = currTime - prevFrameTime;
        prevFrameTime = std::chrono::high_resolution_clock::now();

        AlchemRenderer::Renderer2D::SubmitQuad(transform, logo);
        AlchemRenderer::Renderer2D::SubmitQuad(projection, face);
        AlchemRenderer::Renderer2D::EndScene();

        fps = 1 / elapsed.count();
        timer += elapsed.count();
        if(timer > 1) {
            timer = 0;
            std::cout << fps << " " << AlchemRenderer::Renderer2D::drawCalls << std::endl;
        }

        AlchemRenderer::Window::EndFrame();

    }

    return 0;
}
