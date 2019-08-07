#pragma once

//#ifndef MATRIX_H
//#define MATRIX_H

#include <vector>
#include "Vector2.h"
class Matrix
{
private:
	std::vector<std::vector<float>> mat;
	unsigned rows;
	unsigned cols;
public:
	Matrix(unsigned rows, unsigned cols);
	Matrix(const Matrix& other);
	//virtual ~Matrix();

	Matrix& operator=(Matrix);
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	//Matrix operator*(Matrix&);
	Matrix transpose();

	////Multiplicacion por escalar
	//Matrix operator+(float&);
	//Matrix operator-(float&);
	//Matrix operator*(float&);
	//Matrix operator/(float&);

	////Multiplicacion por vector
	//Vector2 operator*(const Vector2&);
	float& operator()(const unsigned&, const unsigned&);

	unsigned getRows() const;
	unsigned getCols() const;
};
//#endif

