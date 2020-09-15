#ifndef _INPUT_H
#define _INPUT_H

#include <stdbool.h>
#include <SDL2/SDL.h>

struct input {
    SDL_Event event;
};
typedef struct input Input;

Input *createInput(SDL_Event event);
void destroyInput(Input *input);

bool isInputKeyDown(Input *input, SDL_Keycode keycode);
bool isInputKeyUp(Input *input, SDL_Keycode keycode);
bool isInputKeyQuit(Input *input);

#endif //_INPUT_H
