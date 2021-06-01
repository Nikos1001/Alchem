
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../types.h"

namespace AlchemRenderer {

    struct WindowSize {
        i32 w, h;
    };

    class Window {
    public:
        static void Open();
        static bool ShouldClose();
        static void EndFrame();
        static WindowSize GetSize();
    private:
        static GLFWwindow* window;

    };
}
