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
    Sprite *tree = createSprite(&window, "assets\\tree.png", 42, 42);
    
    Vec2 treePos = createVec2(0, 0);
    const float speed = 8.0;
    
    // NOTE(mechap): window settings
    printf("window title: %s\n", window->get_window_title(window));
    printf("window X: %d\n", window->get_window_x(window));
    printf("window Y: %d\n", window->get_window_y(window));
    printf("window Width: %d\n", window->get_window_width(window));
    printf("window Height: %d\n", window->get_window_height(window));
    
    printf("sprite drawn: %s\n", tree->get_sprite_path(&tree));
    
    SDL_Event e;
    Input *input = NULL;
    
    while (!quit) {
        frameStart = SDL_GetTicks();
        
        while (SDL_PollEvent(&e)) {
            input = createInput(e);
            
            if (input->is_input_key_quit(input)) {
                quit = true;
            }
            /*
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
            */
        }
        
        windowClear(&window);
        
        // NOTE(mechap): update position
        treePos.add_func(&treePos, 1, 0);
        
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