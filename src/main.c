#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(void){

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "SDL_Init failed %s\n", SDL_GetError());
    }   


    SDL_Quit();
    return EXIT_SUCCESS;
}