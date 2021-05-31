
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace AlchemRenderer {
    class Window {
    public:
        static void Open();
        static bool ShouldClose();
        static void EndFrame();
    private:
        static GLFWwindow* window;

    };
}
