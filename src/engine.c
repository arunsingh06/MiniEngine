#include "engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

static SDL_Window *window;

bool Engine_Init(void){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }

    if((window = SDL_CreateWindow("Window", 0, 0, 500, 500, 0)) == NULL){
        fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
        Engine_Shutdown();
        return false;
    }

    return true;
}

void Engine_Run(void){

}

void Engine_Shutdown(void){
    if(window != NULL){
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}