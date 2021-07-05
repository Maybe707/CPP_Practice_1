#include <iostream>

void foonc(int array[], int range)
{
    for(int i = 0; i < range; i++)
    {
        std::cout << array[i] << std::endl;
    }
}
    

int main()
{
    int array[3][3] = { {5, 4, 6},
                        {7, 3, 7},
                        {8, 1, 9}};
    int range = 3;

    std::cout << array[2][0] << std::endl;

    foonc(array[2], range);

    return 0;
} 
