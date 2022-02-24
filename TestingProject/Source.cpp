#include <iostream>
#include "../MatrixLibrary/Matrix/Matrix.h"
#include "../MatrixLibrary/Matrix/Matrix.cpp"

int main() {
	int rows = 2;
	int cols = 3;
	Matrix<double> m(rows, cols);
	m.setElements();
	std::cout << m;
	m = 2.0 * m * m.transpose();
	std::cout << m;


	return 0;
}