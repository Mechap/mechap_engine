#include "Core.h"
#include <stdio.h>

int initCore(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "can't init sdl2: %s\n", SDL_GetError());
        return -1;
    }
    
    int flags = IMG_INIT_PNG;
    if (IMG_Init(flags) < 0) {
        fprintf(stderr, "can't init sdl2_image: %s\n", SDL_GetError());
        return -1;
    }
    
    return 0;
}

void quitCore(void) {
    IMG_Quit();
    SDL_Quit();
}