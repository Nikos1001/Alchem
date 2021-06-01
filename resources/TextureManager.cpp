
#include "TextureManager.h"
#include "../renderer/TextureUtils.h"
#include "../runtime/Runtime.h"
#include "ResourceManager.h"
#pragma once

namespace AlchemResource {

    TextureManager::TextureManager(Alchem::Runtime *rt) : ResourceManager<AlchemRenderer::Texture>(rt) {

    }

    AlchemRenderer::Texture *TextureManager::GetByStringIdentifier(const string &identifier) {
        string path = runtime->GetPath(identifier);
        auto texture = new AlchemRenderer::Texture(AlchemRenderer::LoadTexture(path));
        return texture;
    }

}