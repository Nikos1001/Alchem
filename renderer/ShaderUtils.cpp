
#pragma once
#include "ShaderUtils.h"
#include <GL/glew.h>

namespace AlchemRenderer {

    ui32 CreateShader(string source, ui32 shaderType) {
        const char* src = source.c_str();
        ui32 shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &src, NULL);
        glCompileShader(shader);

        i32 success;
        char infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cout << "Shader compilation error:\n" << infoLog << std::endl;
        }
        return shader;
    }

    ui32 CreateProgram(ui32 vertShader, ui32 fragShader) {
        ui32 shaderProgram;
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertShader);
        glAttachShader(shaderProgram, fragShader);
        glLinkProgram(shaderProgram);

        i32 success;
        char infoLog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "Shader link error:\n" << infoLog << std::endl;
        }

        glDeleteShader(vertShader);
        glDeleteShader(fragShader);

        return shaderProgram;
    }

    void BindProgram(ui32 program) {
        glUseProgram(program);
    }

    ui32 GetUniformLocation(ui32 program, const string& uniformName) {
        return glGetUniformLocation(program, uniformName.c_str());
    }

    void Mat4Uniform(ui32 program, const string& uniformName, glm::mat4 value) {
        glUniformMatrix4fv(GetUniformLocation(program, uniformName), 1, GL_FALSE, &value[0][0]);
    }

    void IntUniform(ui32 program, const string& uniformName, i32 value) {
        glUniform1i(GetUniformLocation(program, uniformName), value);
    }

}