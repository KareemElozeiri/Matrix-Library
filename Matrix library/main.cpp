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
	
	Matrix m1 = m*2;
	std::cout << m - m1;
	std::cout << m1-m;
	std::cout << m + m1;

	
	return 0;
}