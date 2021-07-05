#include <iostream>
#include "VertexMath.h"

int main()
{
	Matrix<float, 4> matrix1(2);
	Matrix<float, 4> matrix2(3);
	Matrix<float, 4> matrix3(1);

	Vector<float, 4> vector1;
	Vector<float, 4> vector2;

	for(int i = 0; i < 4; ++i)
		vector1[i] = i;

	vector2 = vector1 * matrix1;

	for(int j = 0; j < 4; ++j)
		std::cout << vector2[j] << std::endl;

	return 0;
}
