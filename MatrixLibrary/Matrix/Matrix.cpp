#include "Matrix.h"
#include <iostream>


template <typename T>
Matrix<T>::Matrix(int rows_num, int cols_num)
{
	this->rows_num = rows_num;
	this->cols_num = cols_num;
	this->matrix = new double* [this->rows_num];

	for (int i = 0; i < this->rows_num; i++) {
		this->matrix[i] = new double[this->cols_num];
	}

	this->setElements(0.0);

}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& mat)
{
	this->rows_num = mat.rows_num;
	this->cols_num = mat.cols_num;
	this->matrix = new double* [this->rows_num];
	for (int i = 0; i < this->rows_num; i++) {
		this->matrix[i] = new double[this->cols_num];
	}

	for (int row = 0; row < this->rows_num; row++) {
		for (int col = 0; col < this->cols_num; col++) {
			this->matrix[row][col] = mat.matrix[row][col];
		}
	}
}

template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < this->rows_num; i++) {
		delete[] this->matrix[i];
	}

	delete[] this->matrix;
}

template <typename T>
int Matrix<T>::getRowNum() const
{
	return this->rows_num;
}

template <typename T>
int Matrix<T>::getColNum() const
{
	return this->cols_num;
}

template <typename T>
void Matrix<T>::setElements() {
	for (int row = 0; row < this->rows_num; row++) {
		for (int col = 0; col < this->cols_num; col++) {
			std::cout << "Enter entery (" << row << "," << col << ") : ";
			std::cin >> this->matrix[row][col];
			std::cout << std::endl;
		}
	}
}

template <typename T>
void Matrix<T>::setElements(T value) {
	for (int i = 0; i < this->rows_num; i++) {
		for (int j = 0; j < this->cols_num; j++) {
			this->matrix[i][j] = value;
		}
	}

}

template <typename T>
void Matrix<T>::setElements(T** p) {
	//copying everything in p to the matrix double pointer
	for (int i = 0; i < this->rows_num; i++) {
		for (int j = 0; j < this->cols_num; j++) {
			this->matrix[i][j] = p[i][j];
		}
	}
}

template <typename T>
void Matrix<T>::setElement(int row, int col, T value) {
	this->matrix[row][col] = value;
}

template <typename T>
T Matrix<T>::getElement(int row, int col) const {
	return this->matrix[row][col];
}


template <typename T>
T* Matrix<T>::getRow(int row_num) const {
	double* row = this->matrix[row_num];
	return row;
}


template <typename T>
T* Matrix<T>::getCol(int col_num) const {
	double* col = new double[this->rows_num];
	for (int i = 0; i < this->rows_num; i++) {
		col[i] = this->matrix[i][col_num];
	}
	return col;
}

template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T> mat)
{
	if (this == &mat) {
		return *this;
	}
	if (this->rows_num != mat.rows_num || this->cols_num != mat.cols_num) {
		for (int i = 0; i < this->rows_num; i++) {
			delete[] this->matrix[i];
		}
		delete this->matrix;
		this->rows_num = mat.rows_num;
		this->cols_num = mat.cols_num;
		//alocating memory 
		this->matrix = new double* [this->rows_num];

		for (int i = 0; i < this->rows_num; i++) {
			this->matrix[i] = new double[this->cols_num];
		}
	}

	for (int i = 0; i < this->rows_num; i++) {
		for (int j = 0; j < this->cols_num; j++) {
			this->matrix[i][j] = mat.matrix[i][j];
		}
	}

	return *this;
}

template <typename T>
Matrix<T> operator*(const Matrix<T> matL, const Matrix<T> matR)
{
	try {
		if (matL.cols_num != matR.rows_num) {
			throw std::string("Invalid matrix multiplications: dimensions do not match!");
		}
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(1);
	}

	Matrix<T> result(matL.rows_num, matR.cols_num);
	for (int i = 0; i < matL.rows_num; i++) {
		for (int j = 0; j < matR.cols_num; j++) {
			result.matrix[i][j] = 0;
			for (int k = 0; k < matL.cols_num; k++) {
				result.matrix[i][j] += matL.matrix[i][k] * matR.matrix[k][j];
			}
		}
	}

	return result;

}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> mat)
{
	try {
		if (this->rows_num != mat.rows_num || this->cols_num != mat.cols_num)
			throw std::string("Addition Error: dimensions do not match !");
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(1);
	}
	Matrix result(mat.rows_num, mat.cols_num);

	for (int row = 0; row < this->rows_num; row++) {
		for (int col = 0; col < this->cols_num; col++) {
			result.matrix[row][col] = this->matrix[row][col] + mat.matrix[row][col];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> mat)
{
	try {
		if (this->rows_num != mat.rows_num || this->cols_num != mat.cols_num)
			throw std::string("Subtraction Error: dimensions do not match !");
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(1);
	}
	Matrix<T> result(mat.rows_num, mat.cols_num);

	for (int row = 0; row < this->rows_num; row++) {
		for (int col = 0; col < this->cols_num; col++) {
			result.matrix[row][col] = this->matrix[row][col] - mat.matrix[row][col];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::transpose(bool inplace)
{
	Matrix<T> trans(this->cols_num, this->rows_num);
	for (int row = 0; row < this->rows_num; row++) {
		for (int col = 0; col < this->cols_num; col++) {
			trans.matrix[col][row] = this->matrix[row][col];
		}
	}
	return trans;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat)
{
	os << std::endl;
	for (int row = 0; row < mat.rows_num; row++) {
		for (int col = 0; col < mat.cols_num; col++) {
			os << mat.matrix[row][col] << " ";
		}
		os << std::endl;
	}

	return os;
}

template <typename T>
Matrix<T> operator*(Matrix<T> mat, T scalar)
{
	Matrix<T> result(mat.rows_num, mat.cols_num);
	for (int row = 0; row < mat.rows_num; row++) {
		for (int col = 0; col < mat.cols_num; col++) {
			result.matrix[row][col] = scalar * mat.matrix[row][col];
		}
	}
	return result;
}

template <typename T>
Matrix<T> operator*(T scalar, Matrix<T> mat)
{
	Matrix<T> result(mat.rows_num, mat.cols_num);
	for (int row = 0; row < mat.rows_num; row++) {
		for (int col = 0; col < mat.cols_num; col++) {
			result.matrix[row][col] = scalar * mat.matrix[row][col];
		}
	}
	return result;

}

template <typename T>
Matrix<T> operator+=(Matrix<T>& matL, const Matrix<T>& matR) {
	Matrix<T> temp(matL.rows_num, matL.cols_num);
	for (int row = 0; row < matL.rows_num; row++) {
		for (int col = 0; col < matL.cols_num; col++) {
			temp.matrix[row][col] = matL.matrix[row][col] + matR.matrix[row][col];
		}
	}
	matL = temp;
	return temp;
}

template <typename T>
Matrix<T> operator-=(Matrix<T>& matL, const Matrix<T>& matR) {
	Matrix<T> temp(matL.rows_num, matL.cols_num);
	for (int row = 0; row < matL.rows_num; row++) {
		for (int col = 0; col < matL.cols_num; col++) {
			temp.matrix[row][col] = matL.matrix[row][col] - matR.matrix[row][col];
		}
	}
	matL = temp;
	return temp;
}

template <typename T>
Matrix<T> operator*=(Matrix<T>& matL, const Matrix<T>& matR) {
	try {
		if (matL.cols_num != matR.rows_num) {
			throw std::string("Invalid matrix multiplications: dimensions do not match!");
		}
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(1);
	}

	Matrix<T> result(matL.rows_num, matR.cols_num);
	for (int i = 0; i < matL.rows_num; i++) {
		for (int j = 0; j < matR.cols_num; j++) {
			result.matrix[i][j] = 0;
			for (int k = 0; k < matL.cols_num; k++) {
				result.matrix[i][j] += matL.matrix[i][k] * matR.matrix[k][j];
			}
		}
	}
	matL = result;
	return result;
}



