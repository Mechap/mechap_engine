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
};
typedef struct sprite Sprite;

Sprite *createSprite(Window **window, const char *spritePath, int width, int height);
void destroySprite(Sprite **sprite);

void drawSprite(Window **window, Sprite **sprite, int spriteX, int spriteY, int spriteWidth, int spriteHeight, int drawX, int drawY, int drawWidth, int drawHeight);
void drawSpriteFull(Window **window, Sprite **sprite, int x, int y);

// NOTE(mechap): getters
SDL_Rect getSrcRect(Sprite **sprite);
SDL_Rect getDstRect(Sprite **sprite);

// NOTE(mechap): setters
void setSrcRect(Sprite **sprite, SDL_Rect rect);
void setDstRect(Sprite **sprite, SDL_Rect rect);

#endif //_SPRITE_H
