#ifndef __GAME_HPP__
#define __GAME_HPP__

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

class Game {
    public:
        static SDL_Renderer *_renderer;
        static SDL_Event _event;

        Game();
        ~Game();

        void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
        void update();
        void render();
        void clean();
        void handle_events();
        bool running() {
            return _isRunning;
        }

    private:
        int _cnt = 0;
        bool _isRunning;
        SDL_Window *_window;

};

#endif