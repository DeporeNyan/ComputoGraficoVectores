#pragma once
#include<cmath>
#include <iostream>
using namespace std;

class Vector2
{
public:
	float x, y, z;
	Vector2() {};
	Vector2(int, int);
	Vector2(float, float, float);

	float productoPunto(const Vector2& vector2);
	float magnitud();
	void vectorNormal();

	Vector2 productoCruz(const Vector2& vector2);
	Vector2 operator+ (Vector2);
	Vector2 operator- (Vector2);
	Vector2 operator* (float);
	Vector2 operator/(float);
	Vector2 operator=(const Vector2);

	void setValues(float, float, float);
	void Print(); 
	void ModifyVector();
};

