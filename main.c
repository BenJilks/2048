#include <stdio.h>
#include "Window.h"

int main()
{
	WM_Open("Testing", 800, 600);
	while (!WM_ShouldClose())
	{
		Vec2f container = {0.5f, 0};
		WM_StartContainer(container);

		Vec2i start = {-(700/2), 10};
		Vec2i size = {700, 500};
		Vec3f colour = {1, 1, 1};
		WM_DrawRect(start, size, colour);
		WM_Update();
	}
	WM_Close();
	return 0;
}

