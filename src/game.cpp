#include "game.hpp"
#include "texture_manager.hpp"
#include "ECS/components.hpp"
#include "vector_2d.hpp"

Manager manager;
Manager* pointManager = &manager;
SDL_Renderer* Game::_renderer = nullptr;
SDL_Event Game::_event;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsystems initialized." << endl;
        _window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(_window) {
            cout << "Window created." << endl;
        }
        _renderer = SDL_CreateRenderer(_window, -1, 0);
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
        if(_renderer) {
            cout << "Renderer created." << endl;
        }
        _isRunning = true;
    }
}

void Game::update() {
    manager.refresh();
    manager.update();
    //newPlanet.getComponent<TransformComponent>()._position.add(Vector2D(5, 0));
}

void Game::render() {
    SDL_RenderClear(_renderer);
    manager.draw();
    SDL_RenderPresent(_renderer);

}

void Game::clean() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
    cout << "Game cleaned." << endl;
}

void Game:: handle_events() {
    while(SDL_PollEvent(&Game::_event)) {
        switch(_event.type) {
            case SDL_QUIT:
                _isRunning = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(Game::_event.button.button == SDL_BUTTON_LEFT) {
                    auto& newPlanet(manager.addEntity());
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    newPlanet.addComponent<TransformComponent>(x, y, pointManager);
                    newPlanet.addComponent<SpriteComponent>("../assets/planet.png");
                }
        }
    }
}

