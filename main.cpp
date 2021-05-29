#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "utils.h"
#include "renderer/ShaderUtils.h"
#include <string>
#include <fstream>
#include "renderer/BufferUtils.h"
#include <random>
#include "glm/ext.hpp"
#include "renderer/Renderer2D.h"

int main() {
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
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

    i32 n = 30000;

    array<glm::mat4> transforms(n);
    glm::mat4 projection = glm::ortho<float>(-4, 4, -3, 3, -100, 100);
    for(int i = 0; i < n; i++) {
        glm::mat4 transform = glm::translate(projection, glm::vec3(8 * (float)rand() / (float)RAND_MAX - 4, 6 * (float)rand() / (float)RAND_MAX - 3, 0));
        transform = glm::rotate(transform, 10 * (float)rand() / (float)RAND_MAX, glm::vec3(0, 0, 1));
        transform = glm::scale(transform, glm::vec3(0.5 * (float)rand() / (float)RAND_MAX, 0.5 * (float)rand() / (float)RAND_MAX, 1));
        transforms[i] = transform;
    }

    AlchemRenderer::Renderer2D::Initialize();

    auto prevFrameTime = std::chrono::high_resolution_clock::now();

    f32 fps = 0;
    f32 timer = 0;
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        AlchemRenderer::Renderer2D::BeginScene();

        auto currTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = currTime - prevFrameTime;
        prevFrameTime = std::chrono::high_resolution_clock::now();
        fps = 1 / elapsed.count();
        timer += elapsed.count();
        if(timer > 1) {
            timer = 0;
            std::cout << fps << std::endl;
        }
//        std::cout << 1 / elapsed.count() << std::endl;
//        glfwSetWindowTitle(window, ("FPS: " + std::to_string(1 / elapsed.count())).c_str());

        for(int i = 0; i < n; i++) {
            AlchemRenderer::Renderer2D::SubmitQuad(transforms[i]);
        }

        AlchemRenderer::Renderer2D::EndScene();

        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glfwTerminate();

    return 0;
}
