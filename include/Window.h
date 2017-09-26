#ifndef WINDOW_H
#define WINDOW_H

#include "Vector.h"

typedef struct Font
{
	char name[80];
	int size;
} Font;
//Font* WM_NewFont(const char* name, int size);

void WM_Open(const char* title, int width, int height);
int WM_ShouldClose();
void WM_Update();
void WM_StartContainer(Vec2f point);
void WM_DrawRect(Vec2i start, Vec2i size, Vec3f colour);
//void WM_DrawText(const char* msg, Vec2f position, Font* font) {}
void WM_Close();

#endif //WINDOW_H

