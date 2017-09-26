#ifndef WINDOW_H
#define WINDOW_H

#include "Vector.h"

void WM_Open(const char* title, int width, int height);
int WM_ShouldClose();
void WM_Update();

void WM_StartContainer(Vec2f point);
void WM_DrawRect(Vec2i start, Vec2i size, Vec3f colour);
void WM_DrawText(const char* msg, Vec2i position, const char* fontName, int size, Vec3f colour);

void WM_Close();

#endif //WINDOW_H

