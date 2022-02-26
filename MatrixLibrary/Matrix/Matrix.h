#pragma once
#include <iostream>


template <typename T>
class Matrix
{
public:
	Matrix(int rows_num, int cols_num); //constructor 
	Matrix(const Matrix&);				//copy constructor 
	~Matrix();							//destructor

	//getters for matrix dimensions
	int getRowNum() const;
	int getColNum() const;

	//setter for all elements in the matrix
	void setElements();
	void setElements(T value);
	void setElements(T** p);
	//setter for a specific element in the matrix 
	void setElement(int row, int col, T value);
	//getter for a specific element in the matrix 
	T getElement(int row, int col) const;
	//getters for specific rows and columns 
	T* getRow(int row) const;
	T* getCol(int col) const;


	//overloading the equal operator for matrices
	Matrix<T> operator=(const Matrix<T> mat);
	//overloading the operator << for printing out the matrix
	template<typename T>
	friend std::ostream& operator<<(std::ostream& cout, const Matrix<T>& mat);
	//overloading the multiplication operator for multiplying matrices
	template<typename T>
	friend Matrix<T> operator*(const Matrix<T> matL, const Matrix<T> matR);
	//overloading the multiplication operator for multiplying matrix by scalar
	template<typename T>
	friend Matrix<T> operator*(Matrix<T> mat, T scalar);
	template<typename T>
	friend Matrix<T> operator*(T scalar, Matrix<T> mat);

	template<typename T>
	friend Matrix<T> operator+=(Matrix<T>& matL, const Matrix<T>& matR);
	template<typename T>
	friend Matrix<T> operator-=(Matrix<T>& matL, const Matrix<T>& matR);
	template<typename T>
	friend Matrix<T> operator*=(Matrix<T>& matL, const Matrix<T>& matR);

	//overloading the addition operator for adding matrices
	Matrix<T> operator+(const Matrix<T> mat);
	//overloading the subtraction operator for subtracting matrices 
	Matrix<T> operator-(const Matrix<T> mat);
	//function for getting trasnpose of the matrix and returning that transpose of the matrix 
	Matrix<T> transpose(bool inplace = false);

private:
	int rows_num;
	int cols_num;
	//the main table that contains all of our matrix elements 
	T** matrix;
};

#include "Matrix.cpp"