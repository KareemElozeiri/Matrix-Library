#include <iostream>
#include "Matrix.h"



int main() {
	int rows = 2;
	int cols = 3;
	Matrix m(rows,cols);
	m.setElements();
	std::cout << m;
	m *= m.transpose();
	std::cout << m;
	

	return 0;
}