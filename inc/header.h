#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdlib.h>
#include "./SDL2.framework/Versions/A/Headers/SDL.h"
#include <time.h>

int randomNumber(int nr_min, int nr_max);

static const int width = 1224;

static const int height = 768;
SDL_Event event;

#endif