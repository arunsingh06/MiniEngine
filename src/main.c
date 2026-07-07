#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "../include/engine.h"

int main(void){

    if(!Engine_Init()){
        return EXIT_FAILURE;
    }
    Engine_Run();

    Engine_Shutdown();
    return EXIT_SUCCESS;
}