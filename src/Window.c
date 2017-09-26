#include "Window.h"
#include <string.h>
#include <SDL2/SDL.h>

/* Window data */
int shouldClose;
SDL_Window* window;
SDL_Renderer* renderer;
char title[80];
int width, height;

/* Container data */
Vec2i containerStart;

void WM_Open(const char* name, int w, int h)
{
	strcpy(title, name);
	width = w; height = h;
	shouldClose = 0;
	containerStart.x = 0;
	containerStart.y = 0;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(name, 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

int WM_ShouldClose()
{
	return shouldClose;
}

Vec3i NormalizedToRGB(Vec3f colour)
{
	Vec3i rgb;
	rgb.x = colour.x * 255;
	rgb.y = colour.y * 255;
	rgb.z = colour.z * 255;
	return rgb;
}

void WM_StartContainer(Vec2f point)
{
	containerStart.x = point.x * width;
	containerStart.y = point.y * height;
}

void WM_DrawRect(Vec2i start, Vec2i size, Vec3f colour)
{
	Vec3i rgb = NormalizedToRGB(colour);
	
	start.x += containerStart.x;
	start.y += containerStart.y;
	SDL_Rect rect = {start.x, start.y, size.x, size.y};
	SDL_SetRenderDrawColor(renderer, rgb.x, rgb.y, rgb.z, 255);
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
	SDL_GetWindowSize(window, &width, &height);
}

void WM_Close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

