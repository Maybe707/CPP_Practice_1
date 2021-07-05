#include <ctime>
#include <endian.h>
#include <iostream>

class Interface;

class A
{
    A* m_value;
    public:
    A()
    {
        std::cout << "A" << std::endl;
    }
    A(A* a) : m_value(a) {}
};

class B : public A
{
    int m_value2;
    public:
    B()
    {
        std::cout << "B" << std::endl;
    }
    B(A* a) : A(a) {}
};

class C : public B
{
    int m_value3;
    public:
    C()
    {
        std::cout << "C" << std::endl;
    }
    C(B* b) : B(b) {}
};

int main()
{
    A* b_pointer = new B();
    A* c_pointer = new C();
    return 0;
}
