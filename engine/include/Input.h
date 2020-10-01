#ifndef _INPUT_H
#define _INPUT_H

#include <stdbool.h>
#include <SDL2/SDL.h>

struct input {
    SDL_Event event;
    
    // NOTE(mechap): func_ptr
    bool (*is_input_key_dowm)(struct input*, SDL_Keycode keycode);
    bool (*is_input_key_up)(struct input*, SDL_Keycode keycode);
    bool (*is_input_key_quit)(struct input*);
};
typedef struct input Input;

Input *createInput(SDL_Event event);
void destroyInput(Input *input);

static bool isInputKeyDown(Input *input, SDL_Keycode keycode);
static bool isInputKeyUp(Input *input, SDL_Keycode keycode);
static bool isInputKeyQuit(Input *input);

#endif //_INPUT_H
