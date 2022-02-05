#include <iostream>
#include "Matrix.h"

void printArray(double* arr,int size) {
	for (int i = 0; i < size; i++) {
		std::cout<<arr[i] <<" " << std::endl;
	}
	std::cout<<std::endl;
}

int main() {
	int rows = 3;
	int cols = 3;
	Matrix m(rows,cols);
	m.setElements();
	m.printMatrix();
	std::cout << "Getting column 1 and row 1:"<<std::endl;
	printArray(m.getCol(1), rows);
	printArray(m.getRow(1), cols);

	
	return 0;
}