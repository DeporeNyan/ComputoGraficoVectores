#pragma once
#include <vector>
#include "Vector2.h"
#include <math.h>
#include <cmath>
#include <iostream>
#ifndef  Matrix_H
#define Matrix_H

class Matrix
{
protected:
	std::vector<std::vector<float>> mat;
private:
	unsigned rows;
	unsigned cols;
public:
	Matrix();
	Matrix(unsigned rows, unsigned cols);
	Matrix(const Matrix& other);
	virtual ~Matrix();
	//Matrix(unsigned, unsigned, int);
	//virtual ~Matrix();

	//void ModMatrix(int value, int rows, int cols);

	Matrix& operator=(Matrix);
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);
	Matrix transpose();
	Matrix identity();

	////Multiplicacion por escalar
	Matrix operator+(float&);
	Matrix operator-(float&);
	Matrix operator*(float&);
	Matrix operator/(float&);
	Vector2 operator*(const Vector2&);

	////Multiplicacion por vector
	//Vector2 operator*(const Vector2&);
	float& operator()(const unsigned&, const unsigned&);

	unsigned getRows() const;
	unsigned getCols() const;
	void ModifyMatrix(); 
	void VectorInMatrix(Vector2&, Vector2&);
	void Print();
};
#endif

