#include <iostream>

unsigned short *(*func1())[]
{
    return reinterpret_cast<unsigned short *(*)[]>(100);
}



int main()
{
    unsigned short* (*(*funcPointer)())[] = func1;
    unsigned short* (*(**pointPointer1)())[] = &funcPointer;
    unsigned short *(*(**bazz[][7])())[] = {
    {pointPointer1, pointPointer1, pointPointer1, pointPointer1},
    {pointPointer1, pointPointer1, pointPointer1},
    {pointPointer1, pointPointer1}
    };

    std::cout << (*bazz[0][0])() << std::endl; 

    /*auto foo_ptr = &func1;
    unsigned short *(*(**bazz[][7])())[] = {
      {&foo_ptr, &foo_ptr, &foo_ptr, &foo_ptr, &foo_ptr, &foo_ptr},
      {&foo_ptr, &foo_ptr, &foo_ptr, &foo_ptr},
      {&foo_ptr, &foo_ptr, &foo_ptr}
    };

    std::cout << (*bazz[0][0])() << std::endl;*/

    return 0;
}
