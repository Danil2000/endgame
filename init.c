#include "/Users/dyanchuk/Desktop/ENDGAME/inc/header.h"

void initSDL(void)
{
	
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	
	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app->window = SDL_CreateWindow("Shooter 02", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlags);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app->renderer = SDL_CreateRenderer(app->window, -1, rendererFlags);
}

void cleanup(void)
{
	SDL_DestroyRenderer(app->renderer);
	
	SDL_DestroyWindow(app->window);
	
	SDL_Quit();
}
