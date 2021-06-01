
#include "CameraNode.h"
#include "../../../renderer/Renderer2D.h"
#include "../../../renderer/Window.h"

namespace Alchem {

    CameraNode::CameraNode() : Node2D() {
        cameraSize = 5;
    }

    void CameraNode::BeginRenderFrame() {
        AlchemRenderer::WindowSize windowSize = AlchemRenderer::Window::GetSize();
        f32 wToH = (f32)windowSize.w / (f32)windowSize.h;
        glm::mat4 projection = glm::ortho<float>(-cameraSize * wToH, cameraSize * wToH, -cameraSize, cameraSize, -100, 100);
        AlchemRenderer::Renderer2D::globalTransformation = projection * glm::inverse(GetTransformation());
    }

}