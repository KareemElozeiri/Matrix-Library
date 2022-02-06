#pragma once
#include <iostream>


class Matrix
{
public:
	Matrix(int rows_num, int cols_num); //constructor 
	Matrix(const Matrix&);
	~Matrix();//destructor

	void setElements();
	void setElement(int row, int col,double value);

	double getElement(int row, int col) const;

	double* getRow(int row) const;
	double* getCol(int col) const;


	friend std::ostream&  operator<<(std::ostream& cout, const Matrix& mat);
private:
	int rows_num;
	int cols_num;
	double** matrix;
};

