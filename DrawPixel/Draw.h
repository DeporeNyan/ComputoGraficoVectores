#pragma once
#include "pch.h"
#include "stdio.h"
#include "SDL.h"

class Draw
{
public:
	Draw();
	void DrawPxl(int x, int y, int width, int height, SDL_Renderer* Render, short lineWidth);
	~Draw();
};

