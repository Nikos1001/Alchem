cmake_minimum_required(VERSION 3.17)
project(Alchem)

set(CMAKE_CXX_STANDARD 14)
set(EDITOR true)
set(CMAKE_CXX_FLAGS -L/usr/local/lib/)

file(GLOB Alchem CONFIGURE_DEPENDS "*.h" "*.cpp")

add_executable(Alchem main.cpp types.h renderer/ShaderUtils.h renderer/ShaderUtils.cpp renderer/BufferUtils.h renderer/BufferUtils.cpp renderer/Renderer2D.cpp renderer/Renderer2D.h renderer/stb_image.h renderer/TextureUtils.h renderer/TextureUtils.cpp renderer/Window.cpp renderer/Window.h)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)
pkg_search_module(GLM REQUIRED glm)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})
target_link_libraries(Alchem ${GLFW_LIBRARIES})
target_link_libraries(Alchem ${GLEW_LIBRARIES})
target_link_libraries(Alchem ${GLM_LIBRARIES})


include_directories(/usr/local/include)
link_directories(/usr/local/lib)

link_libraries(${OPENGL})

if (APPLE)
    target_link_libraries(Alchem "-framework OpenGL")
    target_link_libraries(Alchem "-framework GLUT")
endif()