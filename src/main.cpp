#include "game.hpp"

Game *game = nullptr;

int main() {
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    game = new Game();
    game->init("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 1600, false);
    while(game->running()) {
        frameStart = SDL_GetTicks();
        game->handle_events();
        game->update();
        game->render();
        frameTime = SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay-frameTime);
        }
    }
    game->clean();
    return 0;
}
