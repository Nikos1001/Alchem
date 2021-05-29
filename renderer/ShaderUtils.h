
#pragma once
#include "../utils.h"
#include <glm/ext.hpp>

namespace AlchemRenderer {

    ui32 CreateShader(string source, ui32 shaderType);
    ui32 CreateProgram(ui32 vertShader, ui32 fragShader);
    void BindProgram(ui32 program);

    ui32 GetUniformLocation(ui32 program, const string& uniformName);
    void Mat4Uniform(ui32 program, const string& uniformName, glm::mat4 value);

};