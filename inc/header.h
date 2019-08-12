#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "string.h"
#include "math.h"
#include "ctype.h"

#include "./SDL2.framework/Versions/A/Headers/SDL.h"

int randomNumber(int nr_min, int nr_max);

static const int width = 1224;

static const int height = 768; 

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

App *app;

#endif