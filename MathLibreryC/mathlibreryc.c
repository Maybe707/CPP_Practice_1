#include <stdio.h>

void func(int** matrix_1, int** matrix_2, int** matrix_3,
            int row1, int col1, int row2, int col2)
{
    for(int i = 0; i < row1; ++i)
      for(int j = 0; j < col2; ++j)
        for(int l = 0; l < col1; ++l)
        {
            matrix_3[i][j] += matrix_1[i][l] * matrix_2[l][j];
        }
}

int main()
{
    int matrix_1[5][3] =  {{5, 5, 5},
                           {3, 3, 3},
                           {3, 3, 3},
                           {3, 3, 3},
                           {3, 3, 3}};


    int* ptrMatrix_1[5] = {matrix_1[0], matrix_1[1], matrix_1[2],
                           matrix_1[3], matrix_1[4]};
    int** pointerMatrix_1 = ptrMatrix_1;

    int matrix_2[3][4] =  {{3, 3, 3, 3},
                           {3, 3, 3, 3},
                           {3, 3, 3, 3}};

    int* ptrMatrix_2[3] = {matrix_2[0], matrix_2[1], matrix_2[2]};
    int** pointerMatrix_2 = ptrMatrix_2;

    int matrix_3[5][4] = {{0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}};

    int* ptrMatrix_3[5] = {matrix_3[0], matrix_3[1], matrix_3[2],
                           matrix_3[3], matrix_3[4]};
    int** pointerMatrix_3 = ptrMatrix_3;
    
    func(pointerMatrix_1, pointerMatrix_2, pointerMatrix_3, 5, 3, 3, 4);

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 4; ++j)
        {
            printf("%d\n", pointerMatrix_3[i][j]);
        }

    return 0;
}
