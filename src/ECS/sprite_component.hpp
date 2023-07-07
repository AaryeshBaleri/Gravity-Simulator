#ifndef __SPRITE_COMPONENT_HPP__
#define __SPRITE_COMPONENT_HPP__

#include "components.hpp"
#include <SDL2/SDL.h>

class SpriteComponent: public Component {
    private:
        TransformComponent *_transform;
        SDL_Texture *_texture;
        SDL_Rect _srcRect, _destRect;

    public:
        SpriteComponent() = default;
        SpriteComponent(const char* path) {
            set_tex(path);
        }

        void set_tex(const char* path) {
            _texture = TextureManager::load_texture(path);
        }

        void init() override {
            _transform = &_entity->getComponent<TransformComponent>();

            _srcRect.x = _srcRect.y = 0;
            _srcRect.w = _srcRect.h = 32;
            _destRect.w = _destRect.h = 64;
        }
        void update() override {
            _destRect.x = (int)_transform->_position._x;  
            _destRect.y = (int)_transform->_position._y;
        }
        void draw() override {
            TextureManager::draw(_texture, _srcRect, _destRect);
        }
};

#endif