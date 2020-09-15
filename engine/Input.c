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
    return newInput;
}

void destroyInput(Input *input) {
    if (input != NULL) {
        free(input);
        input = NULL;
    }
}

bool isInputKeyDown(Input *input, SDL_Keycode keycode) {
    if (input != NULL) {
        if (input->event.type == SDL_KEYDOWN && input->event.key.keysym.sym == keycode) {
            return true;
        }
    }
    return false;
}

bool isInputKeyUp(Input *input, SDL_Keycode keycode) {
    if (input != NULL) {
        if (input->event.type == SDL_KEYUP && input->event.key.keysym.sym == keycode) {
            return true;
        }
    }
    return false;
}

bool isInputKeyQuit(Input *input) {
    if (input != NULL) {
        if (input->event.type == SDL_QUIT) {
            return true;
        }
    }
    return false;
}