#ifndef _WINDOW_H
#define _WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct window {
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
};
typedef struct window Window;

Window *createWindow(char *title, int x, int y, int width, int height, Uint32 flags);
int createWindowRenderer(Window **window, int index, Uint32 flags);
void destroyWindow(Window **window);

void windowClear(Window **window);
void windowUpdate(Window **window);

void setWindowBackground(Window **window, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void setWindowFullscreen(Window **window, Uint32 flags);

// NOTE(mechap): getters
SDL_Window *getSdlWindow(Window *window);
const char *getWindowTitle(Window *window);
int getWindowX(Window *window);
int getWindowY(Window *window);
int getWindowWidth(Window *window);
int getWindowHeight(Window *window);
int getWindowFlags(Window *window);
SDL_Renderer *getWindowRenderer(Window *window);

// NOTE(mechap): setters
void setSdlWindow(Window **window, SDL_Window *sdl_window);
void setWindowTitle(Window **window, const char *title);
void setWindowX(Window **window, int x);
void setWindowY(Window **window, int y);
void setWindowWidth(Window **window, int width);
void setWindowHeight(Window **window, int height);
void setWindowRenderer(Window **window, SDL_Renderer *renderer);

#endif //_WINDOW_H
