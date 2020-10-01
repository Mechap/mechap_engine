#ifndef _SPRITE_H
#define _SPRITE_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.h"

struct sprite {
    SDL_Surface *sdl_surface;
    SDL_Texture *sdl_texture;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    SDL_RendererFlip flip;
    char *spritePath;
    float angle;
    
    // NOTE(mechap): func ptr : getters
    SDL_Rect (*get_src_rect)(struct sprite**);
    SDL_Rect (*get_dest_rect)(struct sprite**);
    char* (*get_sprite_path)(struct sprite**);
    
    // NOTE(mechap): func_ptr : setters
    void (*set_src_rect)(struct sprite**, SDL_Rect rect);
    void (*set_dest_rect)(struct sprite**, SDL_Rect rect);
};
typedef struct sprite Sprite;

Sprite *createSprite(Window **window, const char *spritePath, int width, int height);
void destroySprite(Sprite **sprite);

void drawSprite(Window **window, Sprite **sprite, int spriteX, int spriteY, int spriteWidth, int spriteHeight, int drawX, int drawY, int drawWidth, int drawHeight);
void drawSpriteFull(Window **window, Sprite **sprite, int x, int y);

// NOTE(mechap): getters
static SDL_Rect getSrcRect(Sprite **sprite);
static SDL_Rect getDstRect(Sprite **sprite);
static char *getSpritePath(Sprite **sprite);

// NOTE(mechap): setters
static void setSrcRect(Sprite **sprite, SDL_Rect rect);
static void setDstRect(Sprite **sprite, SDL_Rect rect);

#endif //_SPRITE_H
