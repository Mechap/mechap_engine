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
    newSprite->colorRect = (SDL_Color){0, 0, 0, 0};
    newSprite->showRect = false;
    
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

void drawSprite(Window **window, Sprite **sprite, SDL_Rect srcRect, SDL_Rect dstRect) {
    if (*sprite != NULL) {
        (*sprite)->srcRect = srcRect;
		(*sprite)->dstRect = dstRect;
        
        SDL_RenderCopyEx((*window)->sdl_renderer, (*sprite)->sdl_texture, &(*sprite)->srcRect, &(*sprite)->dstRect, (*sprite)->angle, NULL, (*sprite)->flip);
    }
}