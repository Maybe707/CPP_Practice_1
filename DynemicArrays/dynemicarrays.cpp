#include <iostream>

int main()
{
    int** array;

    array = new int*[3];
    for(int i = 0; i < 3; ++i)
        array[i] = new int[5];

    for(int j = 0; j < 3; ++j)
        for(int n = 0; n < 5; ++n)
        {
            array[j][n] = j + n;
            std::cout << array[j][n] << std::endl;
        }
    
    for(int m = 0; m < 3; ++m)
        delete [] array[m];
    delete [] array;

    return 0;
}
