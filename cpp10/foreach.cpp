#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int someFunc()
{
    std::cout << "Our function" << std::endl;
}

int main()
{
  const int row = 6;
  const int column = 3;
  int arr[6][3];
  {
    int (&__range1)[6][3] = arr;
    int (*__begin1)[3] = __range1;
    int (*__end1)[3] = __range1 + 6L;
    for(; __begin1 != __end1; ++__begin1)
    {
      int (&row)[3] = *__begin1;
      {
        int (&__range2)[3] = row;
        int * __begin2 = __range2;
        int * __end2 = __range2 + 3L;
        for(; __begin2 != __end2; ++__begin2)
        {
          int elem = *__begin2;
          elem = 4;
          std::cout << elem << std::endl;
        }
        
      }
    }
   
  }
}
