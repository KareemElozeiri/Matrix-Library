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

	this->setElements(0.0);

}

Matrix::Matrix(const Matrix& mat)
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

Matrix::~Matrix() {
	for (int i = 0; i < this->rows_num; i++) {
		delete[] this->matrix[i];
	}

	delete[] matrix;
}

int Matrix::getRowNum() const
{
	return this->rows_num;
}

int Matrix::getColNum() const
{
	return this->cols_num;
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

void Matrix::setElements(double value) {
	for (int i = 0; i < this->rows_num; i++) {
		for (int j = 0; j < this->cols_num; j++) {
			this->matrix[i][j] = value;
		}
	}

}

void Matrix::setElements(double** p) {
	//copying everything in p to the matrix double pointer
	for (int i = 0; i < this->rows_num; i++) {
		for (int j = 0; j < this->cols_num; j++) {
			this->matrix[i][j] = p[i][j];
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

Matrix Matrix::operator=(const Matrix mat)
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

Matrix operator*(const Matrix matL, const Matrix matR)
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

	Matrix result(matL.rows_num, matR.cols_num);
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


Matrix Matrix::operator+(const Matrix mat)
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

Matrix Matrix::operator-(const Matrix mat)
{
	try {
		if (this->rows_num != mat.rows_num || this->cols_num != mat.cols_num)
			throw std::string("Subtraction Error: dimensions do not match !");
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(1);
	}
	Matrix result(mat.rows_num, mat.cols_num);

	for (int row = 0; row < this->rows_num; row++) {
		for (int col = 0; col < this->cols_num; col++) {
			result.matrix[row][col] = this->matrix[row][col] - mat.matrix[row][col];
		}
	}
	return result;
}

Matrix Matrix::transpose(bool inplace)
{
	Matrix trans(this->cols_num,this->rows_num);
	for (int row = 0; row < this->rows_num; row++) {
		for (int col = 0; col < this->cols_num; col++) {
			trans.matrix[col][row] = this->matrix[row][col];
		}
	}
	return trans;
}



std::ostream& operator<<(std::ostream& os, const Matrix& mat)
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

Matrix operator*(Matrix mat, double scalar)
{
	Matrix result(mat.rows_num, mat.cols_num);
	for (int row = 0; row < mat.rows_num; row++) {
		for (int col = 0; col < mat.cols_num; col++) {
			result.matrix[row][col] = scalar * mat.matrix[row][col];
		}
	}
	return result;
}

Matrix operator*(double scalar, Matrix mat)
{
	Matrix result(mat.rows_num, mat.cols_num);
	for (int row = 0; row < mat.rows_num; row++) {
		for (int col = 0; col < mat.cols_num; col++) {
			result.matrix[row][col] = scalar * mat.matrix[row][col];
		}
	}
	return result;
	
}

Matrix operator+=(Matrix& matL, const Matrix& matR) {
	Matrix temp(matL.rows_num, matL.cols_num);
	for (int row = 0; row < matL.rows_num; row++) {
		for (int col = 0; col < matL.cols_num; col++) {
			temp.matrix[row][col] = matL.matrix[row][col] + matR.matrix[row][col];
		}
	}
	matL = temp;
	return temp;
}

Matrix operator-=(Matrix& matL, const Matrix& matR) {
	Matrix temp(matL.rows_num, matL.cols_num);
	for (int row = 0; row < matL.rows_num; row++) {
		for (int col = 0; col < matL.cols_num; col++) {
			temp.matrix[row][col] = matL.matrix[row][col] - matR.matrix[row][col];
		}
	}
	matL = temp;
	return temp;
}

Matrix operator*=(Matrix& matL, const Matrix& matR) {
	try {
		if (matL.cols_num != matR.rows_num) {
			throw std::string("Invalid matrix multiplications: dimensions do not match!");
		}
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(1);
	}

	Matrix result(matL.rows_num, matR.cols_num);
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

