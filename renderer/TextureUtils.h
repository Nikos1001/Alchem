
#pragma once

#include "../types.h"
#include "stb_image.h"
#include <GL/glew.h>

namespace AlchemRenderer {

    ui32 LoadTexture(const string& path);
    void UseTextures(ui32 texture, ui32 slot);

}