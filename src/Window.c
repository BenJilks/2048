#include "Window.h"
#include <string.h>
#include <SDL2/SDL.h>

int shouldClose;
SDL_Window* window;
SDL_Renderer* renderer;

void WM_Open(const char* name, int width, int height)
{
	shouldClose = 0;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(name, 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

int WM_ShouldClose()
{
	return shouldClose;
}

void WM_DrawRect(Vec2f start, Vec2f end, Vec3f colour)
{
	NormalizedToRGB(&colour);

	SDL_Rect rect = {start.x, start.y, end.x, end.y};
	SDL_SetRenderDrawColor(renderer, colour.x, colour.y, colour.z, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void WM_Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				shouldClose = 1;
				break;
		}
	}
	
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void WM_Close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

