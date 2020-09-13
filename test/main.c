#include "Core.h"
#include "Window.h"
#include "Sprite.h"

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (initCore() != 0) {
        fprintf(stderr, "can't init core!\n");
        return -1;
    }
    
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    bool quit = false;
    
    Window *window = createWindow("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    if (createWindowRenderer(&window, -1, 0) != 0) {
        fprintf(stderr, "error at createWindowRenderer()!\n");
    }
    
    // NOTE(mechap): create entity
    Sprite *tree = createSprite(&window, "assets/tree.png", 42, 42);
    SDL_Rect srcTree = {0, 0, 0, 0};
    SDL_Rect destTree = {0, 0, 0, 0};
    
    // NOTE(mechap): window settings
    printf("window title: %s\n", getWindowTitle(window));
    printf("window X: %d\n", getWindowX(window));
    printf("window Y: %d\n", getWindowY(window));
    printf("window Width: %d\n", getWindowWidth(window));
    printf("window Height: %d\n", getWindowHeight(window));
    
    SDL_Event e;
    
    while (!quit) {
        frameStart = SDL_GetTicks();
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        
        windowClear(&window);
        
        // NOTE(mechap): draw elements...
        drawSprite(&window, &tree, srcTree, destTree);
        
        SDL_Surface *s;
        s = SDL_CreateRGBSurface(0, 50, 50, 32, 0, 0, 0, 0);
        
        SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 255, 0, 0));
        
        windowUpdate(&window);
        
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    destroySprite(&tree);
    destroyWindow(&window);
    quitCore();
    
    return 0;
}