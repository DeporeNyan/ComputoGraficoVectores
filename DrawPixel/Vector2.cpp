#include "pch.h"
#include "Vector2.h"


Vector2::Vector2(int a, int b)
{
	x = a;
	y = b;
}

Vector2 Vector2::operator+ (Vector2 param) {
	Vector2 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return (temp);
}

Vector2 Vector2::operator- (Vector2 param) {
	Vector2 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	return (temp);
}

float Vector2::operator* (Vector2 param) {
	float temp;
	temp = (x * param.x) + (y * param.y);
	return temp;
}

Vector2 Vector2::operator*(float param)
{
	Vector2 temp;
	temp.x = param * this->x;
	temp.y = param * this->y;
	return temp;
}