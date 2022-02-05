#pragma once

template <class enteryType>
class Matrix
{
private:
	int rows_num;
	int cols_num;
	enteryType** matrix;

public:
	Matrix(int rows_num, int cols_num); //constructor 
	Matrix(const Matrix&);
	~Matrix();//destructor

	void setElements();
	void setElement(int row, int col);

	enteryType getElement(int row, int col) const;

	enteryType* getRow(int row) const;
	enteryType* getCol(int col) const;

};

