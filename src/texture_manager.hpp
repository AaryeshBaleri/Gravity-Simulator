#ifndef __TEXTURE_MANAGER_HPP__
#define __TEXTURE_MANAGER_HPP__

#include "game.hpp"

class TextureManager {
    public:
        static SDL_Texture *load_texture(const char* filename);
        static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif