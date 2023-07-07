#ifndef __POSITION_COMPONENT_HPP__
#define __POSITION_COMPONENT_HPP__

#include <iostream>
#include "components.hpp"
#include "../vector_2d.hpp"
#include "ecs.hpp"

class TransformComponent: public Component {
    public:

        Vector2D _position;
        Vector2D _velocity;
        Vector2D _acceleration;
        Manager *_manager;

        float _mass = 3200;

        void init() override {

        }

        TransformComponent() {
            _position._x = 0.0f;
            _position._y = 0.0f;
        }

        TransformComponent(float x, float y, Manager* manager) {
            _position._x = x;
            _position._y = y;
            _velocity._x = 0.0f;
            _velocity._y = 0.0f;
            _acceleration._x = 0.0f;
            _acceleration._y = 0.0f;
            _manager = manager;
        }

        void compute_acceleration() {
            Vector2D acceleration;
            acceleration._x = 0.0f;
            acceleration._y = 0.0f;
            for(auto& e: _manager->_entities) {
                float x1 = e->getComponent<TransformComponent>()._position._x;
                float y1 = e->getComponent<TransformComponent>()._position._y;
                if(x1 > 1600 || x1 < 0 || y1 > 1600 || y1 < 0) {
                    e->destroy();
                    continue;
                }
                float x2 = _position._x;
                float y2 = _position._y;
                int x = x1-x2;
                int y = y1-y2;
                if(x == 0 && y == 0) {
                    continue;
                }
                float distance = sqrt(x*x+y*y);
                float force = (_mass*_mass)/(distance*distance);
                acceleration._x += (force/_mass)*(x/distance);
                acceleration._y += (force/_mass)*(y/distance);
            }
            _acceleration._x = acceleration._x;
            _acceleration._y = acceleration._y;
            cout << "acceleration: " << _acceleration._x << ", " << _acceleration._y << endl;
        }

        void update() override {
            compute_acceleration();
            _velocity._x += _acceleration._x;
            _velocity._y += _acceleration._y;
            cout << "velocity: " << _velocity._x << ", " << _velocity._y << endl;
            _position._x += _velocity._x + 0.5*_acceleration._x;
            _position._y += _velocity._y + 0.5*_acceleration._y;
            cout << "position: " << _position._x << ", " << _position._y << endl;
            std::cout << _manager->_entities.size() << endl;
        }
};

#endif