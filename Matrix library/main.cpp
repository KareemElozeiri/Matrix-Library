#include <iostream>
#include "Matrix.h"

void printArray(double* arr,int size) {
	for (int i = 0; i < size; i++) {
		std::cout<<arr[i] <<" " << std::endl;
	}
	std::cout<<std::endl;
}

int main() {
	int rows = 4;
	int cols = 3;
	Matrix m(rows,cols);
	m.setElements();
	m = m.transpose();

	std::cout << m.getRowNum() << std::endl;
	std::cout << m.getColNum() << std::endl;

	Matrix m1(3,4);
	m1.setElements();
	std::cout << m;
	std::cout << m1;
	Matrix result =  m * m1;

	
	return 0;
}