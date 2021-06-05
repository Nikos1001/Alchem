
#include "Input.h"
#include "../renderer/Window.h"

namespace AlchemInput {

    bool Input::KeyPressed(string key) {
        return glfwGetKey(AlchemRenderer::Window::window, key[0]);
    }
}