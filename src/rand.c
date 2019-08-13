#include "../inc/header.h"

int main() {

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	SDL_Window *win = SDL_CreateWindow("Shooter 02", 0, 0, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Surface *surf = SDL_GetWindowSurface(win);
	SDL_Surface *img = IMG_Load("images/sprites/Michael-Myers.png");
 	SDL_Rect rect = {1, 1, 100, 100};
 
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				exit(0);
			}
		SDL_BlitSurface(img, NULL, surf, &rect);
		SDL_UpdateWindowSurface(win);
		}
 	}
	return 0;
}
