#include "engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


bool Engine_Init(void){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

void Engine_Run(void){

}

void Engine_Shutdown(void){
    SDL_Quit();
}