#include <iostream>

template<class T2, int row2, int col2>
class B
{
public:
    int variable1;
    int variable2;
    
    B() : variable1(row2), variable2(col2)
        {}
    
  
    template<typename T, int row1, int col1>
    int operator*(B<T, row1, col1>& obj);
}; 

template<class T2, int row2, int col2>
template<typename T, int row1, int col1>
int B<T2, row2, col2>::operator*(B<T, row1, col1>& obj)
{
    return obj.variable2 * variable1;
}

int main()
{
    std::cout << std::endl;
    B<int, 2, 8> obj;
  return 0;
}
