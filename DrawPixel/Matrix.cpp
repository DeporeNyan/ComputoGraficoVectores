#include "pch.h"
#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(unsigned _rows, unsigned _cols){
	mat.resize(_rows);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(_cols, 0);
	}
	rows = _rows;
	cols = _cols;
}

Matrix::Matrix(const Matrix& other) {
	mat = other.mat;
	rows = other.getRows();
	cols = other.getCols();
}

Matrix::~Matrix()
{
}

Matrix & Matrix::operator=(Matrix other){
	if (&other == this)
		return*this;
	unsigned newRows = other.getRows();
	unsigned newCols = other.getCols();
	mat.resize(newRows);
	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(newCols);
	}
	for (unsigned i = 0; i < newRows; i++) {
		for (unsigned j = 0; j < newCols; j++) {
			mat[i][j] = other(i, j);
		}
	}
	rows = newRows;
	cols = newCols;
	return*this;
}

Matrix Matrix::operator+(Matrix & mtrx){
	Matrix matriz(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matriz(i, j) = mat[i][j] + mtrx(i, j);
		}
	}
	return matriz;
}

Matrix Matrix::operator-(Matrix &mtrx){
	Matrix matriz(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matriz(i, j) = mat[i][j] - mtrx(i, j);
		}
	}
	return matriz;
}

Matrix Matrix::operator*(Matrix& mtrx){
	Matrix matriz(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matriz(i, j) = 0;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < mtrx.getCols(); j++) {
			for (int k = 0; k < cols; k++) {
				matriz(i, j) += mat[i][k] * mtrx(k, j);
			}
		}
	}
	return matriz;
}

Matrix Matrix::transpose()
{
	Matrix matriz(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			matriz(i, j) = mat[j][i];
		}

	return matriz;
}

Matrix  Matrix::identity()
{
	Matrix matriz(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == j)
				matriz(i, j) = 1;
			else
				matriz(i, j) = 0;
		}
	}
	return matriz;
}

Vector2 Matrix::operator*(const Vector2& vec1) {
	Vector2 vecR(0, 0, 0);

	mat.resize(3);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(3, 0);
	}

	vecR.x = vec1.x * mat[0][0] + vec1.y * mat[0][1] + vec1.z*mat[0][2];
	vecR.y = vec1.x * mat[1][0] + vec1.y * mat[1][1] + vec1.z*mat[1][2];
	vecR.z = vec1.x * mat[2][0] + vec1.y * mat[2][1] + vec1.z*mat[2][2];

	return vecR;
}

Matrix Matrix::operator+(float &number)
{
	Matrix m(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m(i, j) = mat[i][j] + number;
		}
	}
	return m;
}

Matrix Matrix::operator-(float& number)
{
	Matrix m(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m(i, j) = mat[i][j] - number;
		}
	}

	return m;
}

Matrix Matrix::operator*(float &number)
{
	Matrix m(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m(i, j) = mat[i][j] * number;
		}
	}
	return m;
}

Matrix Matrix::operator/(float &number)
{
	Matrix m(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m(i, j) = mat[i][j] / number;
		}
	}
	return m;
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

void Matrix::Print(){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << mat[i][j] << " ";
		}
		printf("\n");
	}
	printf("\n");
}

void Matrix::ModifyMatrix() {
	int a;
	printf("Give me the elements you want in the matrix.\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> a;
			mat[i][j] = a;
		}
	}

}

void Matrix::VectorInMatrix(Vector2 &vec1, Vector2 &vec2){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			mat[0][0] = vec1.x;
			mat[0][1] = vec1.y;
			mat[1][0] = vec2.x;
			mat[1][1] = vec2.y;
		}
	}
}

