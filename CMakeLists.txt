cmake_minimum_required(VERSION 3.17)
project(Alchem)

set(CMAKE_CXX_STANDARD 17)
set(EDITOR true)
set(CMAKE_CXX_FLAGS -L/usr/local/lib/)

file(GLOB Alchem CONFIGURE_DEPENDS "*.h" "*.cpp")
list(APPEND CMAKE_PREFIX_PATH /usr/local/)

add_executable(Alchem main.cpp types.h renderer/ShaderUtils.h renderer/ShaderUtils.cpp renderer/BufferUtils.h renderer/BufferUtils.cpp renderer/Renderer2D.cpp renderer/Renderer2D.h renderer/stb_image.h renderer/TextureUtils.h renderer/TextureUtils.cpp renderer/Window.cpp renderer/Window.h application/Application.cpp application/Application.h runtime/Runtime.cpp runtime/Runtime.h node/Node.cpp node/Node.h node/node2D/Node2D.cpp node/node2D/Node2D.h node/node2D/spriteNode/SpriteNode.cpp node/node2D/spriteNode/SpriteNode.h resources/ResourceManager.cpp resources/ResourceManager.h renderer/Texture.cpp renderer/Texture.h resources/TextureManager.cpp resources/TextureManager.h node/node2D/cameraNode/CameraNode.cpp node/node2D/cameraNode/CameraNode.h)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)
pkg_search_module(GLM REQUIRED glm)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})
target_link_libraries(Alchem PUBLIC ${GLFW_LIBRARIES})
target_link_libraries(Alchem PUBLIC ${GLEW_LIBRARIES})
target_link_libraries(Alchem PUBLIC ${GLM_LIBRARIES})

add_subdirectory(lib/ChaiScript)


if (APPLE)
    target_link_libraries(Alchem PUBLIC "-framework OpenGL")
    target_link_libraries(Alchem PUBLIC "-framework GLUT")
endif()