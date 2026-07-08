#include "../include/engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct{
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
    int width;
    int height;
}Engine;

static Engine engine;

bool Engine_Init(void){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }

    engine.width = 500;
    engine.height = 500;
    engine.window = SDL_CreateWindow("MiniEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, engine.width, engine.height, 0);
    
    if(engine.window == NULL){
        fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }


    engine.renderer = SDL_CreateRenderer(engine.window, -1, SDL_RENDERER_ACCELERATED);
    if(engine.renderer == NULL){
        fprintf(stderr, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(engine.window);
        SDL_Quit();
        return false;
    }
    return true;
}

void Engine_Run(void){

    engine.running = true;

    SDL_Event event;

    while(engine.running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                engine.running = false;
            }
        }

        SDL_SetRenderDrawColor(engine.renderer, 50, 50, 50, 255);
        SDL_RenderClear(engine.renderer);
        SDL_RenderPresent(engine.renderer);
    }
}

void Engine_Shutdown(void){
    if(engine.window != NULL){
        SDL_DestroyWindow(engine.window);
    }
    if(engine.renderer != NULL){
        SDL_DestroyRenderer(engine.renderer);
    }
    SDL_Quit();
}