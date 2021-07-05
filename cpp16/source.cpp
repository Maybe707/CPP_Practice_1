#include <iostream>

int main()
{
	int variable1 = 100;
	int variable2 = 200;

	int* pointer1 = &variable1;
	int* pointer2 = &variable2;

	int** pOnPointer = &pointer1;
	int*** pOnPointer2 = &pOnPointer;

	std::cout << pOnPointer << std::endl;
	std::cout << *pOnPointer << std::endl;
	std::cout << &pOnPointer << std::endl;
	std::cout << **pOnPointer << std::endl;
	std::cout << &pointer1 << std::endl;
	std::cout << pointer1 << std::endl;
	std::cout << &variable1 << std::endl;
	std::cout << &pOnPointer2 << std::endl;
	std::cout << pOnPointer2 << std::endl;
	std::cout << *pOnPointer2 << std::endl;
	std::cout << **pOnPointer2 << std::endl;
	std::cout << ***pOnPointer2 << std::endl;

	int array[8] {};

    int *pi1 = &array[0], *pi2 = &array[5];
    char *pc1 = (char *)pi1, *pc2 = (char *)pi2;
	double* pd1 = (double *)pi1, *pd2 = (double *)pi2;

    std::cout << pi2 - pi1 << std::endl;
    std::cout << pc2 - pc1 << std::endl;
	std::cout << pd2 - pd1 << std::endl;

	return 0;
}
