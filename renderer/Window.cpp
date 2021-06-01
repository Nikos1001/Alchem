
#include "Window.h"
#include <iostream>

#pragma once

namespace AlchemRenderer {
    void AlchemRenderer::Window::Open() {
        glfwInit();
        glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        window = glfwCreateWindow(800, 600, "L'Window", NULL, NULL);
        if (window == NULL) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(window);
        glfwShowWindow(window);

        glewInit();
        glEnable(GL_MULTISAMPLE);
    }

    bool AlchemRenderer::Window::ShouldClose() {
        return glfwWindowShouldClose(window);
    }

    void AlchemRenderer::Window::EndFrame() {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    GLFWwindow* Window::window = nullptr;

    WindowSize Window::GetSize() {
        WindowSize result = {};
        glfwGetWindowSize(window, &result.w, &result.h);
        return result;
    }
}