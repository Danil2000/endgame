#include "../inc/header.h"
<<<<<<< HEAD

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
=======
<<<<<<< HEAD

int main() {

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	SDL_Window *win = SDL_CreateWindow("Shooter 02", 0, 0, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Surface *surf = SDL_GetWindowSurface(win);
	SDL_Surface *img = IMG_Load("images/sprites/перс1.png");
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
=======


SDL_Texture *loadTexture(char *filename)
{
	App app;
 	
 	SDL_Texture *texture;

 	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

 	texture = IMG_LoadTexture(app.renderer, filename);

 	return texture;
}
void prepareScene(void)
{
	App app;
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	App app;
	SDL_RenderPresent(app.renderer);
}

void blit(SDL_Texture *texture, int x, int y)
{
	App app;
	SDL_Rect dest;
	
	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	
	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

int randomNumber(int nr_min, int nr_max) {
	static bool initialized = false;
	if(!initialized) {
		initialized = true;
		srand(time(NULL));
	}

	return rand() % nr_max + nr_min;
}

int randomColor() {
	return randomNumber(0, 255);
}

void drawRandomPoints(int nr_points, bool randomizeColor, SDL_Renderer *renderer) {
	for(int i = 0; i < nr_points; i++) {
		if(randomizeColor) {
			SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
		}
		SDL_RenderDrawPoint(renderer, randomNumber(0, width), randomNumber(0, height));
	}
}

void doInput(void)
{
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}

void initSDL(void)
{	
	App app;

	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("Shooter 02", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlags);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
}

void cleanup(void)
{
	App app;

	SDL_DestroyRenderer(app.renderer);

	SDL_DestroyWindow(app.window);

	SDL_Quit();
}

int main() {
	//bzero(app, sizeof(&app));
	//bzero(player, sizeof(&player));

	
 	Entity player;
	player.x = 100;
	player.y = 100;
	player.texture = loadTexture("./images/Michael-Myers.png");

	SDL_Init(SDL_INIT_VIDEO);

	atexit(cleanup);
	
	while (1)
	{
		prepareScene();
		
		doInput();
		
		blit(player.texture, player.x, player.y);
		
		presentScene();
		
		SDL_Delay(16);
	}

	return 0;
}
>>>>>>> 678a76be3aec40ed7daba81305aee996db23f300
>>>>>>> 18f5427c6eda850f1ceb2f1195fc8f3577f20850
