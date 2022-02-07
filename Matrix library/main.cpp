#include <iostream>
#include "Matrix.h"



int main() {
	int rows = 2;
	int cols = 3;
	Matrix m(rows,cols);
	m.setElements();
	std::cout << m;
	Matrix m2 = m.transpose();
	
	std::cout << m * m2;

	return 0;
}