#include <iostream>

int main()
{
    int var = 10;
    int* pointer = &var;
    

    int array[2] = {2,3};

    std::cout << &var << std::endl;
    
    int** pointer2 = &pointer;
    std::cout << *pointer2 << std::endl;

    return 0;
}


