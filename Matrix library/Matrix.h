#pragma once
#include <iostream>


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
	void setElements(double value);
	void setElements(double** p);
	//setter for a specific element in the matrix 
	void setElement(int row, int col,double value);
	//getter for a specific element in the matrix 
	double getElement(int row, int col) const;
	//getters for specific rows and columns 
	double* getRow(int row) const;
	double* getCol(int col) const;


	//overloading the equal operator for matrices
	Matrix operator=(const Matrix mat);
	//overloading the operator << for printing out the matrix
	friend std::ostream&  operator<<(std::ostream& cout, const Matrix& mat);
	//overloading the multiplication operator for multiplying matrices
	friend Matrix operator*(const Matrix matL,const Matrix matR);
	//overloading the multiplication operator for multiplying matrix by scalar
	friend Matrix operator*(Matrix mat, double scalar);
	friend Matrix operator*(double scalar,Matrix mat);
	
	friend Matrix operator+=(Matrix& matL, const Matrix& matR);
	friend Matrix operator-=(Matrix& matL, const Matrix& matR);
	friend Matrix operator*=(Matrix& matL, const Matrix& matR);

	//overloading the addition operator for adding matrices
	Matrix operator+(const Matrix mat);
	//overloading the subtraction operator for subtracting matrices 
	Matrix operator-(const Matrix mat);
	//function for getting trasnpose of the matrix and returning that transpose of the matrix 
	Matrix transpose(bool inplace = false);

private:
	int rows_num;
	int cols_num;
	//the main table that contains all of our matrix elements 
	double** matrix;
};

