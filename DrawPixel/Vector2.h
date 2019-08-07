#pragma once
#include <iostream>
using namespace std;

class Vector2
{
public:
	int x, y;
	Vector2() {};
	Vector2(int, int);
	Vector2 operator+ (Vector2);
	Vector2 operator- (Vector2);
	float operator* (Vector2);
	Vector2 operator* (float);
	//Vector2 operator= (Vector2);
};

