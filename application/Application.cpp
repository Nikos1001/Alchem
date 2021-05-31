
#include "Application.h"
#include <chrono>

namespace Alchem {

    void Alchem::Application::Run() {
        Start();
        auto prevTimestamp = std::chrono::high_resolution_clock::now();
        while(ShouldContinue()) {

            // Compute frame time
            auto currTimestamp = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = currTimestamp - prevTimestamp;
            prevTimestamp = currTimestamp;
            f32 delta = elapsed.count();

            Update(delta);

        }
    }

    void Application::Start() {

    }

    void Application::Update(f32 delta) {

    }

    bool Application::ShouldContinue() {
        return false;
    }

}
