#include <iostream>

auto sum3(int v1, int v2, int v3)
{
    return v1 + v2 + v3;
}

auto curried_sum3(int v1)
{
    return [=](int v2)
    {
        return [=](int v3)
        {
            return sum3(v1, v2, v3);
        };

    };
}

int main()
{
    std::cout << sum3(38, 3, 1) << std::endl;
    std::cout << curried_sum3(38)(3)(1) << std::endl;
    return 0;
}
