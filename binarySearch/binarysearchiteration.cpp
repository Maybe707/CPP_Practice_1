// array - это массив, в котором мы проводим поиски
// target - это искомое значение
// min - это индекс минимальной границы массива, в котором мы осуществляем поиск
// max - это индекс максимальной границы массива, в котором мы осуществляем поиск
// binarySearch() должен возвращать индекс искомого значения, если оно обнаружено. В противном случае, возвращаем -1
#include <iostream>

int binarySearch(int *array, int target, int min, int max)
{
    int controlMax = (max + min);
    int count = 0;
    int centr;
    do
    {
        centr = (max + min) / 2;
        if (array[centr] == target) {
            return centr;
        }
        if (array[centr] > target) {
            if ((max + min) % 2 == 0) {
                max = (centr - 1);
            } else {
                max = centr;
            }
        }
        if (array[centr] < target) {
            if ((max + min) % 2 == 0) {
                min = (centr + 1);
            } else {
                min = centr;
            }
        }
        ++count;
    }while(count != controlMax);
    return -11;
}

int main()
{
    int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;

    int index = binarySearch(array, x, 0, 14);

    if (array[index] == x)
        std::cout << "Good! Your value " << x << " is on position "<< index << " in array!\n";
    else
        std::cout << "Fail! Your value " << x << " isn't in array!\n";
    return 0;
}
