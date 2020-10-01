#include "Input.h"
#include <stdlib.h>
#include <stdio.h>

Input *createInput(SDL_Event event) {
    Input *newInput = (Input *)malloc(sizeof(Input));
    if (newInput == NULL) {
        fprintf(stderr, "Error! newInput could not be allocated!\n");
        return NULL;
    }
    newInput->event = event;
    
    // NOTE(mechap): init func_ptr
    newInput->is_input_key_dowm = &isInputKeyDown;
    newInput->is_input_key_quit = &isInputKeyQuit;
    newInput->is_input_key_up = &isInputKeyUp;
    
    return newInput;
}

void destroyInput(Input *input) {
    if (input != NULL) {
        free(input);
        input = NULL;
    }
}

//~ NOTE(mechap): static functions

static bool isInputKeyDown(Input *input, SDL_Keycode keycode) {
    if (input != NULL) {
        if (input->event.type == SDL_KEYDOWN && input->event.key.keysym.sym == keycode) {
            return true;
        }
    }
    return false;
}

static bool isInputKeyUp(Input *input, SDL_Keycode keycode) {
    if (input != NULL) {
        if (input->event.type == SDL_KEYUP && input->event.key.keysym.sym == keycode) {
            return true;
        }
    }
    return false;
}

static bool isInputKeyQuit(Input *input) {
    if (input != NULL) {
        if (input->event.type == SDL_QUIT) {
            return true;
        }
    }
    return false;
}