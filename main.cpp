#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "types.h"
#include "glm/ext.hpp"
#include "renderer/Renderer2D.h"
#include <memory>
#include <chrono>
#include "renderer/TextureUtils.h"

int main() {
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 16); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "L'Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwShowWindow(window);

    glewInit();

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
    while(!glfwWindowShouldClose(window))
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

        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glfwTerminate();

    return 0;
}
