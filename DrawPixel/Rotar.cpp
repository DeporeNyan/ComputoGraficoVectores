#include "pch.h"
#include "Rotar.h"
#include <math.h>

float Rotar::setAngle(float _angle) {
	angle = _angle;
	return angle;
}

Rotar::Rotar(float angle)
{
	mat.resize(3);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(3, 0);
	}
	mat[0][0] = std::cos(angle * 3.1416 / 180);
	mat[0][1] = std::sin(angle * 3.1416 / 180);
	mat[1][0] = -std::sin(angle * 3.141 / 180);
	mat[1][1] = std::cos(angle * 3.141 / 180);
}
