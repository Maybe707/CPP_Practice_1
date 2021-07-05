#include <iostream>

template<typename T>
class AddSpace
{
private:
    T const& ref;
public:
    AddSpace(T const& r) : ref(r)
    {}
    friend std::ostream& operator << (std::ostream& os, AddSpace<T> s)
    {
        return os << s.ref << ' ';
    }
};

template<typename ... Args>
void print(Args ... args)
{
    (std::cout << ... << AddSpace<Args>(args)) << '\n';
}

template<typename ... Args>
void printDigits(Args ... args)
{
    std::cout << (... + args) << std::endl;
}

int main()
{
    print(10, true, 100, false, 0.57);

    return 0;
}

 
