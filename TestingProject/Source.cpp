#include <iostream>
#include "../MatrixLibrary/Matrix/Matrix.h"

int main() {
	int rows = 3;
	int cols = 2;
	Matrix<double> m(rows, cols);
	m.setElements();
	std::cout << m;
	m = 2.0 * m * m;
	std::cout << m;


	return 0;
}