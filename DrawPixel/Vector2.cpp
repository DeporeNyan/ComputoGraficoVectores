#include "pch.h"
#include "Vector2.h"


Vector2::Vector2(int a, int b)
{
	x = a;
	y = b;
}

Vector2::Vector2(float a, float b, float c) {
	x = a; y = b; z = c;
}

Vector2 Vector2::operator+ (Vector2 param) {
	Vector2 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	temp.z = z + param.z;
	return Vector2(temp.x, temp.y, temp.z);
}

Vector2 Vector2::operator- (Vector2 param) {
	Vector2 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	temp.z = z - param.z;
	return Vector2(temp.x, temp.y, temp.z);
}

Vector2 Vector2::operator*(float param)
{
	Vector2 temp;
	temp.x = x * param;
	temp.y = x * param;
	temp.z = x * param;
	return Vector2(temp.x, temp.y, temp.z);
}

Vector2 Vector2::operator/(float param)
{
	Vector2 temp;
	temp.x = x / param;
	temp.y = y / param;
	temp.z = z / param;
	return Vector2(temp.x, temp.y, temp.z);
}

Vector2 Vector2::operator=(const Vector2 vec)
{
	return Vector2(x = vec.x, y = vec.y, z = vec.z);
}

void Vector2::setValues(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Vector2::Print() {
	std::cout << "This is your vector: (" << x << ", " << y << ")\n";
}

void Vector2::ModifyVector()
{
	std::cout << "Give me the value of x: ";
	std::cin >> x; printf("\n");
	std::cout << "Give me the value of y: ";
	std::cin >> y; printf("\n\n");
}

float Vector2::productoPunto(const Vector2& vector2) {
	float punto;
	punto = x * vector2.x + y * vector2.y + z * vector2.z;
	return punto;
}

float Vector2::magnitud() {
	return sqrt(x * x + y * y + z * z);
}

void Vector2::vectorNormal() {
	float magn = magnitud();

	if (magn != 0) {
		x /= magn;
		y /= magn;
		z /= magn;
	}

}

Vector2 Vector2::productoCruz(const Vector2& vector2) {
	Vector2 cruz;
	cruz.x = y * vector2.z - z * vector2.y;
	cruz.y = -(x*vector2.z - z * vector2.x);
	cruz.z = x * vector2.y - y * vector2.x;

	return Vector2(cruz.x, cruz.y, cruz.z);
}