#include "Window.h"
#include <stdlib.h>
#include <stdio.h>

Window *createWindow(char *title, int x, int y, int width, int height, Uint32 flags) {
    Window *newWindow = (Window *)malloc(sizeof(Window));
    if (newWindow == NULL) {
        fprintf(stderr, "Error! newWindow1 could not be allocated: %s\n", SDL_GetError());
        return NULL;
    }
    newWindow->sdl_window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (newWindow->sdl_window == NULL) {
        fprintf(stderr, "Error! newWindow->sdl_window could not be allocated: %s\n", SDL_GetError());
        return NULL;
    }
    
    // NOTE(mechap): newWindow->sdl_renderer is NULL by default
    newWindow->sdl_renderer = NULL;
    
    return newWindow;
}

// NOTE(mechap): create renderer for the window
int createWindowRenderer(Window **window, int index, Uint32 flags) {
    if (*window != NULL) {
        (*window)->sdl_renderer = SDL_CreateRenderer((*window)->sdl_window, index, flags);
        if ((*window)->sdl_renderer == NULL) {
            fprintf(stderr, "Error! newWindow->sdl_renderer could not be allocated: %s\n", SDL_GetError());
            return -1;
        }
        return 0;
    }
    fprintf(stderr, "Error! newWindow->sdl_window is not null!");
    return 1;
}

// NOTE(mechap): free window and sdl_window / sdl_renderer
void destroyWindow(Window **window) {
    if (*window == NULL) {
        if ((*window)->sdl_renderer != NULL) {
            SDL_DestroyRenderer((*window)->sdl_renderer);
            (*window)->sdl_renderer = NULL;
        }
        if ((*window)->sdl_window != NULL) {
            SDL_DestroyWindow((*window)->sdl_window);
            (*window)->sdl_window = NULL;
        }
        free(*window);
        *window = NULL;
    }
}

void windowClear(Window **window) {
    if (*window != NULL && (*window)->sdl_renderer != NULL) {
        SDL_RenderClear((*window)->sdl_renderer);
    }
}

void windowUpdate(Window **window) {
    if (*window != NULL && (*window)->sdl_renderer != NULL) {
        SDL_RenderPresent((*window)->sdl_renderer);
    }
}

// NOTE(mechap): set a background rgba color
void setWindowBackground(Window **window, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    if (*window != NULL && (*window)->sdl_renderer != NULL) {
        SDL_SetRenderDrawColor((*window)->sdl_renderer, r, g, b, a);
    }
}

void setWindowFullscreen(Window **window, Uint32 flags) {
    if (*window != NULL) {
        SDL_SetWindowFullscreen((*window)->sdl_window, flags);
    }
}

SDL_Window *getSdlWindow(Window *window) {
    if (window != NULL) {
        return window->sdl_window;
    }
    return NULL;
}

const char *getWindowTitle(Window *window) {
    if (window != NULL) {
        return SDL_GetWindowTitle(window->sdl_window);
    }
    return NULL;
}

int getWindowX(Window *window) {
    if (window != NULL) {
        int x, y;
        SDL_GetWindowPosition(window->sdl_window, &x, &y);
        return x;
    }
    
    // NOTE(mechap): window does not exist
    return -1;
}

int getWindowY(Window *window) {
    if (window != NULL) {
        int x, y;
        SDL_GetWindowPosition(window->sdl_window, &x, &y);
        return y;
    }
    
    // NOTE(mechap): window does not exist
    return -1;
}

int getWindowWidth(Window *window) {
    if (window != NULL) {
        int w, h;
        SDL_GetWindowSize(window->sdl_window, &w, &h);
        return w;
    }
    
    // NOTE(mechap): window does not exist
    return -1;
}

int getWindowHeight(Window *window) {
    if (window != NULL) {
        int w, h;
        SDL_GetWindowSize(window->sdl_window, &w, &h);
        return h;
    }
    
    // NOTE(mechap): window does not exist
    return -1;
}

int getWindowFlags(Window *window) {
    if (window != NULL) {
        return SDL_GetWindowFlags(window->sdl_window);
    }
    
    // NOTE(mechap): window does not exist
    return -1;
}

SDL_Renderer *getWindowRenderer(Window *window) {
    if (window != NULL) {
        return window->sdl_renderer;
    }
    
    return NULL;
}

void setSdlWindow(Window **window, SDL_Window *sdl_window) {
    if (*window != NULL) {
        (*window)->sdl_window = sdl_window;
    }
}

void setWindowTitle(Window **window, const char *title) {
    if (*window != NULL) {
        SDL_SetWindowTitle((*window)->sdl_window, title);
    }
}

void setWindowX(Window **window, int x) {
    if (*window != NULL) {
        int tmpX, y;
        SDL_GetWindowPosition((*window)->sdl_window, &tmpX, &y);
        SDL_SetWindowPosition((*window)->sdl_window, x, y);
    }
}

void setWindowY(Window **window, int y) {
    if (*window != NULL) {
        int x, tmpY;
        SDL_GetWindowPosition((*window)->sdl_window, &x, &tmpY);
        SDL_SetWindowPosition((*window)->sdl_window, x, y);
    }
}

void setWindowWidth(Window **window, int width) {
    if (*window != NULL) {
        int w, h;
        SDL_GetWindowPosition((*window)->sdl_window, &w, &h);
        SDL_SetWindowPosition((*window)->sdl_window, width, h);
    }
}

void setWindowHeight(Window **window, int height) {
    if (*window != NULL) {
        int w, h;
        SDL_GetWindowPosition((*window)->sdl_window, &w, &h);
        SDL_SetWindowPosition((*window)->sdl_window, w, height);
    }
}

void setWindowRenderer(Window **window, SDL_Renderer *renderer) {
    if (*window != NULL) {
        (*window)->sdl_renderer = renderer;
    }
}