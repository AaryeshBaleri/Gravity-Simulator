#include "game_object.hpp"
#include "texture_manager.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y) {
    _xpos = x;
    _ypos = y;
    _objTexture = TextureManager::load_texture(textureSheet);
}

void GameObject::update() {
    _xpos++;
    _ypos++;

    _srcRect.h = 128;
    _srcRect.h = 128;
    _srcRect.x = 0;
    _srcRect.y = 0;

    _destRect.x = _xpos;
    _destRect.y = _ypos;
    _destRect.w = 64;
    _destRect.h = 64;
}

void GameObject::render() {
    SDL_RenderCopy(Game::_renderer, _objTexture, NULL, &_destRect);

}