#pragma once
#include "Matrix.h"
#include <vector>

class Rotar : public Matrix
{
public:
	Rotar(float);
	float setAngle(float);
private:
	float angle;
};

