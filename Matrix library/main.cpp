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
	std::cout << "printing matrix: " << m;
	std::cout << "Getting column 1 and row 1:"<<std::endl;
	
	m.setElement(0, 0, 23);
	Matrix m0 = m;
	std::cout << m0;
	Matrix m_trans = m0.transpose();
	std::cout << m_trans;

	
	return 0;
}