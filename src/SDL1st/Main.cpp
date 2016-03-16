#include <iostream>
#include "SDL.h"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

bool InitEngine();

int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;
	SDL_Surface* screen = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow(
			"SDL 1st", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			printf("Window could not be created! SDL_Error", SDL_GetError());
		}
		else
		{
			screen = SDL_GetWindowSurface(window);

			SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(window);

			SDL_Delay(2000);
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}