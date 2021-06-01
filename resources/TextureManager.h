
#pragma once

#include "../renderer/Texture.h"
#include "ResourceManager.h"

namespace AlchemResource {

    class TextureManager : public ResourceManager<AlchemRenderer::Texture> {
    public:
        TextureManager(Alchem::Runtime* rt);
    private:
        AlchemRenderer::Texture *GetByStringIdentifier(const string& identifier) override;
    };

}