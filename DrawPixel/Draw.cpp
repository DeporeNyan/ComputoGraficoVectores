#include "pch.h"
#include "Draw.h"
#include <stdio.h>
#include <SDL.h>


Draw::Draw(){}

void Draw::DrawPxl(int x, int y, int width, int height, SDL_Renderer* Render, short lineWidth)
{
	int w = width; int h = height;
	if (lineWidth > 0)
	{
		for (unsigned short i = 0; abs(lineWidth) > i; i++)
		{
			SDL_RenderDrawPoint(Render, w / 2 + x * 60 - i, h / 2 - (y * 60 - i));
		}
	}
	else
		for (unsigned short i = 0; abs(lineWidth) > i; i++)
		{
			SDL_RenderDrawPoint(Render, w / 2 + x * 60 + i, h / 2 - (y * 60 + i));
		}
}

Draw::~Draw(){}
