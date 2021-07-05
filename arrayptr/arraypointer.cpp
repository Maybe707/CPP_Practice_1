#include <iostream>
#include <typeinfo>

int** func(int** array)
{
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 3; ++j)
            std::cout << array[i][j] << std::endl;
    return array;
}

int func2(int* ar, int row, int col)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            std::cout << ar[i*col+j] << std::endl;

    return 10;
}

void myFunc(double *a,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            *(a+ i*rows + j)+=10.0;
        }
    }
}

void printArray(double *a,int rows,int cols){
    std::cout<<"Printing your array...\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            std::cout<<*(a+ i*rows + j)<<"  ";
        }
        std::cout<<std::endl;
    }
}

void printArr(double *arr, int range)
{
    for(int i = 0; i < range; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void Arr(double *arr, int range)
{
    for(int i = 0; i < range; ++i)
    {
        arr[i] = 101;
    }
}

int**** func3(int**** array)
{
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int h = 0; h < 3; ++h)
                for(int m = 0; m < 4; ++m)
                std::cout << array[i][j][h][m] << std::endl;

    return array;
}



int main()
{
    /*int array[2][3] = {{2, 5, 6},
                       {76, 5, 87}};
    int* p[2] = {array[0], array[1]};
    int** pp = p;

    double array2[2][2][2][2][2][2][2][2][2][2];
    double *pointer = &(**********array2);
    double *pointer = &(array2[0][0][0][0][0][0][0][0][0][0]);

    Arr(pointer, 1024);
    printArr(pointer, 1024);*/

    int array3[2][2][3];
    int (*ptr)[2][3] = {array3};
    int (*ptr2)[3] = *ptr;
    int *ptr3 = *ptr2; 

    int arr[2][2][3][4] {
        {{ { 1, 2, 3, 4 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 } }},
            {{ { 1, 2, 3, 4 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 } }}
    };

    //int arr[2][2][3][4] {};
    
    int *p[2][2][3] {
        {
            { arr[0][0][0], arr[0][0][1], arr[0][0][2] },
            { arr[0][1][0], arr[0][1][1], arr[0][1][2] }
        },
        {
            { arr[1][0][0], arr[1][0][1], arr[1][0][2] },
            { arr[1][1][0], arr[1][1][1], arr[1][1][2] }
        }
    };

     int **pp[2][2] {
      { p[0][0], p[0][1] },
      { p[1][0], p[1][1] }
     };
  
    int ***ppp[2] {
      pp[0], pp[1]
    };
  
    int ****pppp = ppp;

    func3(pppp);

    return 0;
}














