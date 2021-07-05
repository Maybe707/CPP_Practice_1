#include <iostream>

// Генерируем рандомное число между значениями min и max.
// Предполагается, что функцию srand() уже вызывали
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    
    std::cout << getRandomNumber(0, 2) << std::endl;
    std::cout << getRandomNumber(0, 2) << std::endl;
    std::cout << getRandomNumber(0, 2) << std::endl;
    std::cout << getRandomNumber(0, 2) << std::endl;
    std::cout << getRandomNumber(0, 2) << std::endl;

    return 0;
}
