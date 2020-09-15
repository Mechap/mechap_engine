#include "Sprite.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Sprite *createSprite(Window **window, const char *spritePath, int width, int height) {
    Sprite *newSprite = (Sprite *)malloc(sizeof(Sprite));
    if (newSprite == NULL) {
        fprintf(stderr, "Error! newSprite could not be allocated!\n");
        return NULL;
    }
    
    // NOTE(mechap): allocate enough spaces to copy spritePath
    const size_t size = sizeof(char) * (strlen(spritePath) + 1);
    newSprite->spritePath = (char *)malloc(size);
    if (newSprite->spritePath == NULL) {
        fprintf(stderr, "Error! newSprite->spritePath could not be allocated!\n");
        return NULL;
    }
    memcpy(newSprite->spritePath, spritePath, size);
    
    newSprite->sdl_surface = IMG_Load(newSprite->spritePath);
    if (newSprite->spritePath == NULL) {
        printf("Unnable to load image %s! Error: %s\n", newSprite->spritePath, IMG_GetError());
        return NULL;
    }
    newSprite->sdl_texture = SDL_CreateTextureFromSurface((*window)->sdl_renderer, newSprite->sdl_surface);
    if (newSprite->sdl_texture == NULL) {
        fprintf(stderr, "Error! newSprite->sdl_texture could not be loaded from newSprite->sdl_surface!\n");
        return NULL;
    }
    
    newSprite->srcRect = (SDL_Rect){0, 0, 0, 0};
    newSprite->dstRect = (SDL_Rect){0, 0, width, height};
    newSprite->flip = SDL_FLIP_NONE;
    newSprite->angle = 0.0;
    
    return newSprite;
}

void destroySprite(Sprite **sprite) {
    if (*sprite != NULL) {
        if ((*sprite)->sdl_surface != NULL) {
            SDL_FreeSurface((*sprite)->sdl_surface);
            (*sprite)->sdl_surface = NULL;
        }
        if ((*sprite)->sdl_texture != NULL) {
            SDL_DestroyTexture((*sprite)->sdl_texture);
            (*sprite)->sdl_texture = NULL;
        }
        if ((*sprite)->spritePath != NULL) {
            free((*sprite)->spritePath);
            (*sprite)->spritePath = NULL;
        }
        free(*sprite);
        *sprite = NULL;
    }
}

void drawSprite(Window **window, Sprite **sprite, int spriteX, int spriteY, int spriteWidth, int spriteHeight, int drawX, int drawY, int drawWidth, int drawHeight) {
    if (*sprite != NULL) {
        // NOTE(mechap): set the texture_rect
        (*sprite)->srcRect.x = spriteX;
		(*sprite)->srcRect.y = spriteY;
        (*sprite)->srcRect.w = spriteWidth;
        (*sprite)->srcRect.h = spriteHeight;
        
        // NOTE(mechap): set the render_rect
        (*sprite)->dstRect.x = drawX;
        (*sprite)->dstRect.y = drawY;
        (*sprite)->dstRect.w = drawWidth;
        (*sprite)->dstRect.h = drawHeight;
        
        SDL_RenderCopyEx((*window)->sdl_renderer, (*sprite)->sdl_texture, &(*sprite)->srcRect, &(*sprite)->dstRect, (*sprite)->angle, NULL, (*sprite)->flip);
    }
}

void drawSpriteFull(Window **window, Sprite **sprite, int x, int y) {
    if (*sprite != NULL) {
        (*sprite)->dstRect.x = x;
        (*sprite)->dstRect.y = y;
        
        SDL_RenderCopyEx((*window)->sdl_renderer, (*sprite)->sdl_texture, NULL, &(*sprite)->dstRect, (*sprite)->angle, NULL, (*sprite)->flip);
    }
}

SDL_Rect getSrcRect(Sprite **sprite) {
    if (*sprite != NULL) {
        return (*sprite)->srcRect;
    }
    
    // NOTE(mechap): empty rect
    return (SDL_Rect){0, 0, 0, 0};
}

SDL_Rect getDstRect(Sprite **sprite) {
    if (*sprite != NULL) {
        return (*sprite)->dstRect;
    }
    
    // NOTE(mechap): empty rect
    return (SDL_Rect){0, 0, 0, 0};
}

void setSrcRect(Sprite **sprite, SDL_Rect rect) {
    if (*sprite != NULL) {
        (*sprite)->srcRect = rect;
    }
}

void setDstRect(Sprite **sprite, SDL_Rect rect) {
    if (*sprite != NULL) {
        (*sprite)->dstRect = rect;
    }
}
