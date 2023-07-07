/*#ifndef __KEYBOARD_CONTROLLER__
#define __KEYBOARD_CONTROLLER__

#include "../game.hpp"
#include "ecs.hpp"
#include "components.hpp"

class KeyboardController: public Component {
    public:
        TransformComponent* _transform;

        void init() override {
            _transform = &_entity->getComponent<TransformComponent>();
        }

        void update() override {
            if(Game::_event.type == SDL_KEYDOWN) {
                switch(Game::_event->key.keysym.sym) {
                    case SDLK_
                }
            }
            if(Game::_event.type == SDL_KEYUP)
        }
};

#endif*/