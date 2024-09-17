#pragma once
#include "Matrix.h"

class Escalar : public Matrix
{
public:
	Escalar(int sx, int sy);
	int setSX(int);
	int setSY(int);
private:
	int sx, sy;
};

