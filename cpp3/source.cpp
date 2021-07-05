#include <iostream>

int main(int argc, char* argv[])
{

    int array2[5] = {3, 6, 7, 3, 1};
    int *pointer3 = array2;
    int (*pointer5)[5] = &array2;

    std::cout << pointer5 << std::endl;
    std::cout << *pointer5 << std::endl;
    std::cout << **pointer5 << std::endl;
    std::cout << &pointer5 << std::endl;
    
    std::cout << &array2 << std::endl;
    std::cout << pointer3 << std::endl;
    std::cout << array2 << std::endl;
    std::cout << *pointer3 << std::endl;
    std::cout << pointer3[0] << std::endl;
    
    
    int array[3][3] = {{5, 6, 1},
                       {2, 5, 7},
                       {8, 9, 333}};
    int (*pointer[1])[3][3] = {&array}; 
    int (*pointer2)[3][3] = &array;

    int array3[2][2][2];

    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                array3[i][j][k] = 3;

    int (*pointer4)[2][2][2] = &array3;

    std::cout << array << std::endl;
    std::cout << &array << std::endl;
    std::cout << *pointer << std::endl;
    std::cout << **pointer << std::endl;
    std::cout << ***pointer << std::endl;
    std::cout << **pointer2 << " String N 25 " << std::endl;

    std::cout << ***pointer2 << std::endl;

    std::cout << ****pointer << " string N28 " <<  std::endl;

    std::cout << **array+1 << std::endl;

    std::cout << array[2][2]+100 << std::endl;

    std::cout << *array[1]+100 << std::endl;

    int value = 100;
    int *ptr = &value;

    int **ptr2 = &ptr;

    std::cout << value << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << **ptr2 << std::endl;
    std::cout << &value << std::endl;
    std::cout << ptr << std::endl;
    std::cout << *ptr2 << std::endl;
    std::cout << &ptr << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << &ptr2 << std::endl;

    return 0;
}

