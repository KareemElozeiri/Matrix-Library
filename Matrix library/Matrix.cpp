#include "Matrix.h"
#include <iostream>


Matrix::Matrix(int rows_num, int cols_num)
{
	this->rows_num = rows_num;
	this->cols_num = cols_num;
	this->matrix = new double*[this->rows_num];

	for (int i = 0; i < this->rows_num;i++) {
		this->matrix[i] = new double[this->cols_num];
	}
	std::cout << "constructor called"<<std::endl;

}

Matrix::Matrix(const Matrix&)
{
}

Matrix::~Matrix() {
	for (int i = 0; i < this->rows_num; i++) {
		delete[] this->matrix[i];
	}

	delete[] matrix;
	std::cout << "destructor called" << std::endl;
}

void Matrix::setElements() {
	for (int row = 0; row < this->rows_num; row++) {
		for (int col = 0; col < this->cols_num; col++) {
			std::cout << "Enter entery (" << row << "," << col << ") : ";
			std::cin >> this->matrix[row][col];
			std::cout << std::endl;
		}
	}
}

void Matrix::setElement(int row, int col,double value) {
	this->matrix[row][col] = value;
}

double Matrix::getElement(int row, int col) const {
	return this->matrix[row][col];
}


double* Matrix::getRow(int row_num) const {
	double* row = this->matrix[row_num];
	return row;
}


double* Matrix::getCol(int col_num) const {
	double* col = new double[this->rows_num];
	for (int i = 0; i < this->rows_num; i++) {
		col[i] = this->matrix[i][col_num];
	}
	return col;
}



std::ostream& operator<<(std::ostream& cout, const Matrix& mat)
{
	std::cout << std::endl;
	for (int row = 0; row < mat.rows_num; row++) {
		for (int col = 0; col < mat.cols_num; col++) {
			std::cout << mat.matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}

	return cout;
}
