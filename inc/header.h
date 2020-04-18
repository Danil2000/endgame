#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "string.h"
#include "math.h"
#include "ctype.h"

#include "./SDL2.framework/Headers/SDL.h"
#include "./SDL2_image.framework/Headers/SDL_image.h"

int randomNumber(int nr_min, int nr_max);

static const int width = 1224;
const int height = 768;

SDL_Texture *loadTexture(char *filename);

void blit(SDL_Texture *texture, int x, int y);
SDL_Event event;

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

typedef struct {
	int x;
	int y;
	SDL_Texture *texture;
} Entity;


#endif
