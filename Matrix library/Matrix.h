#pragma once

template <class enteryType>
class Matrix
{
private:
	int rows_num;
	int cols_num;
	enteryType** matrix;

public:
	Matrix(int rows_num, int cols_num);

	void setElements();
	void setElement(int row, int col);

	enteryType getElement(int row, int col) const;

	enteryType* getRow() const;
	enteryType* getCol() const;

};

