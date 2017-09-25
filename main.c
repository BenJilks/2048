#include <stdio.h>
#include "Window.h"

int main()
{
	WM_Open("Testing", 800, 600);
	while (!WM_ShouldClose())
	{
		WM_Update();
	}
	WM_Close();
	return 0;
}

