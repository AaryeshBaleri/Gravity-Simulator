#ifndef __GAME_OBJECT_HPP__
#define __GAME_OBJECT_HPP__

#include "game.hpp"

class GameObject {
    public:
        GameObject(const char* textureSheet, int x, int y);
        ~GameObject();
        
        void update();
        void render();

    private:
        int _xpos;
        int _ypos;
        SDL_Texture* _objTexture;
        SDL_Rect _srcRect, _destRect;
};

#endif