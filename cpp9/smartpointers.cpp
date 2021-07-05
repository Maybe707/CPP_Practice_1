#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <locale>

class Units
{
public:
    int m_value;
    //Units(int value) : m_value(value)
    //{}

    int getValue()
    {
        return m_value;
    }
};

struct Robots
{
    int m_variable1;
    int m_variable2;
    int m_variable3;
};

int main()
{
    Units obj{20};
    Robots robot{22, 55, 77};
    Units* pointer = &obj;
    std::cout << pointer->getValue() << std::endl;
    std::cout << obj.getValue() << std::endl;
    std::cout << robot.m_variable1 << " " << robot.m_variable2 << " " << robot.m_variable3 << std::endl;

    std::initializer_list<std::initializer_list<int>>::const_iterator it;
    std::initializer_list<int>::const_iterator iterator;
    std::initializer_list<std::initializer_list<int>> list = {{4, 2, 5, 6, 7},
                                                              {1, 6, 7, 3, 6},
                                                              {5, 2, 7, 8, 9}};
    it = list.begin();
    iterator = it->begin();
    int array[5][3];
    for(int i = 0; it != list.end(); ++iterator, ++i)
    {
        iterator = it->begin();
        ++it;
        for(int j = 0; j < 5; ++j)
        {
            array[i][j] = *iterator;
            std::cout << array[i][j] << std::endl;
            ++iterator;
        }
    }
    return 0;
}
