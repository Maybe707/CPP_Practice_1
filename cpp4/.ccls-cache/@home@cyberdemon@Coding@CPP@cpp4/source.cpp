#include <iostream>

class World;

int foonc(World wld);

class World
{
    int m_variable = 200;

public:

    int methodFunc()
    {
        foonc(*this);
    }

friend int foonc(World wld);
};

int foonc(World wld)
{
    return wld.m_variable + 100;
}

int main()
{
    World object;
    std::cout << object.methodFunc() << std::endl;
    return 0;
}
