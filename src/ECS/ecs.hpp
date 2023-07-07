#ifndef __ECS_HPP__
#define __ECS_HPP__

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "../vector_2d.hpp"


using namespace std;

class Component;
class Entity;

using ComponentID = size_t;

inline ComponentID getComponentTypeID() {
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept {   
    static ComponentID typeID{ getComponentTypeID() };
    return typeID;
}

constexpr size_t maxComponents = 32;

using ComponentBitset = bitset<maxComponents>;
using ComponentArray = array<Component*, maxComponents>;

class Component {
    public:
        Entity* _entity;
        virtual void init() {}
        virtual void update() {}
        virtual void draw() {}
        virtual ~Component() {}
};

class Entity {
    private:
        bool _active = true;
        vector<unique_ptr<Component>> _components;
        ComponentArray _componentArray;
        ComponentBitset _componentBitset;

    public:
        void update() {
            for(auto &c: _components) {
                c->update();
            }
        }
        void draw() {
            for(auto &c: _components) {
                c->draw();
            }
        }
        bool is_active() const {
            return _active;
        }
        void destroy() {
            _active = false;
        }

        template<typename T> bool hasComponent() const {
            return _componentBitset[getComponentTypeID<T>()];
        }

        template<typename T, typename... TArgs>
        T& addComponent(TArgs&&... mArgs) {
            T* c(new T(forward<TArgs>(mArgs)...));
            c->_entity = this;
            unique_ptr<Component> uPtr{ c };
            _components.emplace_back(move(uPtr));

            _componentArray[getComponentTypeID<T>()] = c;
            _componentBitset[getComponentTypeID<T>()] = true;

            c->init();
            return *c;
        }
        
        template<typename T> T& getComponent() const {
            auto ptr(_componentArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        } 
};

class Manager {
    public:
    vector<unique_ptr<Entity>> _entities;

     void update() {
        for (auto &e: _entities) {
            e->update();
        }
     } 
    void draw() {
        for(auto &e: _entities) {
            e->draw();
        }
     }
    void refresh() {
        _entities.erase(remove_if(_entities.begin(), _entities.end(), 
            [](const unique_ptr<Entity> &mEntity) {
                return !mEntity->is_active();
        }), 
            _entities.end());
     }

    Entity& addEntity() {
        Entity* e = new Entity();
        unique_ptr<Entity> uPtr { e };
        _entities.emplace_back(move(uPtr));
        return *e;
     }

};

#endif