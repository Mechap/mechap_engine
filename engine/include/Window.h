#ifndef _WINDOW_H
#define _WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct window {
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    
    // NOTE(mechap): func ptr : getters
    SDL_Window* (*get_sdl_window)(struct window*);
    const char* (*get_window_title)(struct window*);
    int (*get_window_x)(struct window*);
    int (*get_window_y)(struct window*);
    int (*get_window_width)(struct window*);
    int (*get_window_height)(struct window*);
    int (*get_window_flags)(struct window*);
    SDL_Renderer* (*get_window_renderer)(struct window*);
    
    // NOTE(mechap): func ptr : setters
    void (*set_sdl_window)(struct window**, SDL_Window*);
    void (*set_window_title)(struct window**, const char*);
    void (*set_window_x)(struct window**, int);
    void (*set_window_y)(struct window**, int);
    void (*set_window_width)(struct window**, int);
    void (*set_window_height)(struct window**, int);
    void (*set_window_renderer)(struct window**, SDL_Renderer*);
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
static SDL_Window *getSdlWindow(Window *window);
static const char *getWindowTitle(Window *window);
static int getWindowX(Window *window);
static int getWindowY(Window *window);
static int getWindowWidth(Window *window);
static int getWindowHeight(Window *window);
static int getWindowFlags(Window *window);
static SDL_Renderer *getWindowRenderer(Window *window);

// NOTE(mechap): setters
static void setSdlWindow(Window **window, SDL_Window *sdl_window);
static void setWindowTitle(Window **window, const char *title);
static void setWindowX(Window **window, int x);
static void setWindowY(Window **window, int y);
static void setWindowWidth(Window **window, int width);
static void setWindowHeight(Window **window, int height);
static void setWindowRenderer(Window **window, SDL_Renderer *renderer);

#endif //_WINDOW_H
