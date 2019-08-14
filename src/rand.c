#include "../inc/header.h"

int main() {

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	SDL_Window *win = SDL_CreateWindow("Chernobyl", 0, 0, 1024, 1024, SDL_WINDOW_SHOWN);
	SDL_Surface *surf = SDL_GetWindowSurface(win);
	SDL_Surface *background = IMG_Load("images/sprites/фон.png");
	//SDL_ConvertSurface(background, surf->format, 0);
	bool frback = 0;
	SDL_Surface *img = IMG_Load("images/sprites/pers.png");
 	SDL_Rect pers = {0, 150, 100, 100};
	
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				exit(0);
			}
			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_UP){
					pers.y -= 16;
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
				{
						pers.x += 16;
				}
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					pers.x -= 16;
					free(img);
						img = IMG_Load("images/sprites/rpers.png");
						SDL_Rect rpers = {pers.x, pers.y, 100, 100};
						SDL_BlitSurface(img, NULL, surf, &rpers);
						frback = 1;
				}
				if(frback == 1 && event.key.keysym.sym == SDLK_RIGHT)
				{
					free(img);
						img = IMG_Load("images/sprites/pers.png");
						SDL_Rect rpers = {pers.x, pers.y, 100, 100};
						SDL_BlitSurface(img, NULL, surf, &rpers);
				}
				if(event.key.keysym.sym == SDLK_DOWN)
				{
					pers.y += 16;
				}
	
				if(pers.x > 858)
				{
					pers.x -= 16;
				}
				if(pers.y > 858)
				{
					pers.y -= 16;
				}
			}
		}

		//SDL_Rect pers = {1, 150, 100, 100};
		SDL_Rect fon = {0, 0, 1024, 1024};	
		SDL_BlitSurface(background, NULL, surf, &fon);	
		SDL_BlitSurface(img, NULL, surf, &pers);
		SDL_UpdateWindowSurface(win);
	}

 	SDL_FreeSurface(img);
 	SDL_FreeSurface(background);
	return 0;
}
