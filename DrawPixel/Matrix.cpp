#include "pch.h"
#include "Matrix.h"

Matrix::Matrix(const Matrix& other) {
	mat = other.mat;
	rows = other.getRows();
	cols = other.getCols();
}

Matrix::Matrix(unsigned rows, unsigned cols) {
	mat.resize(rows);
	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(cols, 0);
	}
	rows = rows;
	cols = cols;
}


Matrix& Matrix::operator=(Matrix other) {
	if (&other == this)
		return *this;
	unsigned new_rows = other.getRows();
	unsigned new_cols = other.getCols();
	mat.resize(new_rows);
	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(new_cols);
	}
	for (unsigned i = 0; i < new_rows; i++) {
		for (unsigned j = 0; j < new_cols; j++) {
			mat[i][j] = other(i, j);
		}
	}

	rows = new_rows;
	cols = new_cols;
	return *this;
}

Matrix Matrix::operator+(Matrix& other) {
	Matrix temp(rows, cols);
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			temp(i, j) = mat[i][j] + other(i, j);
		}
	}
	return temp;
}

Matrix Matrix::operator-(Matrix& other) {
	Matrix temp(rows, cols);
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			temp(i, j) = mat[i][j] - other(i, j);
		}
	}
	return temp;
}

Matrix Matrix::transpose() {
	Matrix result(rows, cols);
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			result(i, j) = this->mat[j][i];
		}
	}
	return result;
}

float& Matrix::operator()(const unsigned& row, const unsigned& col) {
	return this->mat[row][col];
}

unsigned Matrix::getRows() const {
	return this->rows;
}

unsigned Matrix::getCols() const {
	return this->cols;
}

//void Matrix::Print()
//{
//
//}
