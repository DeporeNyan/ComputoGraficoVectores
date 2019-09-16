#pragma once
#include "Matrix.h"

class Trasladar : public Matrix
{
public:
	void setVX(int);
	void setVY(int);

	Trasladar(int vx, int vy);
private:
	int vx, vy;
};

