#include "/Users/dyanchuk/Desktop/ENDGAME/inc/header.h"

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
int main(int argc, char **argv) {
	App *app = NULL;
	Entity *player = NULL;

	player->x = 100;
	player->y = 100;
	player->texture = loadTexture("./images/Michael-Myers.png");

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Chernobyl, SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool running = true;
		while(running) {
			while(SDL_PollEvent(&event)) {
				if(event.type == SDL_QUIT) {
					running = false;
				}
			}	
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); //Yellow color
			drawRandomPoints(500, true, renderer);

			SDL_RenderPresent(renderer);
		}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);

		SDL_Quit();
		return 0;
}



