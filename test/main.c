#include "Core.h"
#include "Window.h"
#include "Sprite.h"
#include "Vec2.h"
#include "Input.h"

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
    
    // NOTE(mechap): create entity and initialize it
    Sprite *tree = createSprite(&window, "assets/tree.png", 42, 42);
    
    Vec2 treePos = createVec2(0, 0);
    const float speed = 5.0;
    
    // NOTE(mechap): window settings
    printf("window title: %s\n", getWindowTitle(window));
    printf("window X: %d\n", getWindowX(window));
    printf("window Y: %d\n", getWindowY(window));
    printf("window Width: %d\n", getWindowWidth(window));
    printf("window Height: %d\n", getWindowHeight(window));
    
    printf("sprite drawn: %s\n", tree->spritePath);
    
    SDL_Event e;
    Input *input = NULL;
    
    while (!quit) {
        frameStart = SDL_GetTicks();
        
        while (SDL_PollEvent(&e)) {
            input = createInput(e);
            
            if (isInputKeyQuit(input)) {
                quit = true;
            }
            
            if (isInputKeyDown(input, SDLK_a)) {
                // NOTE(mechap): move left
                treePos.x -= 1 * speed;
            } else if (isInputKeyDown(input, SDLK_d)) {
                // NOTE(mechap): move right
                treePos.x += 1 * speed;
            } else if (isInputKeyDown(input, SDLK_w)) {
                // NOTE(mechap): move up
                treePos.y -= 1 * speed;
            } else if (isInputKeyDown(input, SDLK_s)) {
                treePos.y += 1 * speed;
            }
        }
        
        windowClear(&window);
        
        // NOTE(mechap): draw elements...
        drawSpriteFull(&window, &tree, treePos.x, treePos.y);
        
        windowUpdate(&window);
        
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    destroySprite(&tree);
    destroyInput(input);
    destroyWindow(&window);
    quitCore();
    
    return 0;
}