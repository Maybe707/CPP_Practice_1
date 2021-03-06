#include <iostream>
#include <type_traits>

template<class T, int row, int col>
class Matrix
{
public:
    int matrixRow;
    int matrixCol;
    T matrix[row][col];
    Matrix() : matrixRow(row), matrixCol(col)
    {
        int value = 1;
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
            {
                matrix[i][j] = value;
                ++value;
            }
        /*
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
            {
                std::cout << "output in destructor" << std::endl;
                std::cout << matrix[i][j] << std::endl;
            }
        */
    }

    /*Matrix(const Matrix<T, row, col>& matrix)
        {
            T (*newPointer)[col] = this->matrix;
            for(int i = 0; i < row; i++)
                for(int j = 0; j < col; j++)
                {
                    newPointer[2][2];
                }
        }
    */

    Matrix<T, col, row> matrixTranspose()
        {
            Matrix<T, col, row> tempTranceponentMatrix;
            for(int i = 0; i < row; ++i)
                for(int j = 0; j < col; ++j)
                {
                    tempTranceponentMatrix[j][i] = matrix[i][j];
                }
            return tempTranceponentMatrix;
        }

    template<class T2, int row2, int col2>
    Matrix<T, row, col2> operator*(Matrix<T2, row2, col2>& matrix2);

    T operator()(const int index1, const int index2);
    T* operator[](const int index);
    Matrix<T, row, col> operator-(Matrix<T, row, col>& matrix2);
    Matrix<T, row, col> operator+(Matrix<T, row, col>& matrix2);
    Matrix<T, row, col> operator*(T variable);
    friend Matrix<T, row, col> operator*(T variable, Matrix<T, row, col>& matrix2);
};

template<class T, int row, int col>
template<typename T2, int row2, int col2>
Matrix<T, row, col2> Matrix<T, row, col>::operator*(Matrix<T2, row2, col2>& matrix2)
{
    Matrix<T, row, col2> tempMatrix;
  for (int x = 0; x < row; ++x)
    for (int z = 0; z < col2; ++z) {
        tempMatrix.matrix[x][z] = 0;
    }
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col2; ++j)
            for(int l = 0; l < col; ++l)
            {
                tempMatrix.matrix[i][j] += matrix[i][l] * matrix2.matrix[l][j];
            }
    for(int n = 0; n < row; ++n)
        for(int m = 0; m < col2; ++m)
        {
            std::cout << tempMatrix.matrix[n][m] << std::endl;
        }

    return tempMatrix;
}

template <class T, int row, int col>
T Matrix<T, row, col>::operator()(const int index1, const int index2)
{
    return matrix[index1][index2];
}

template <class T, int row, int col>
T* Matrix<T, row, col>::operator[](const int index)
{
    return matrix[index];
}

template<class T, int row, int col>
Matrix<T, row, col> Matrix<T, row, col>::operator-(Matrix<T, row, col>& matrix2)
{
    Matrix<T, row, col> tempMatrix;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            {
                tempMatrix[i][j] = matrix[i][j] - matrix2.matrix[i][j];
            }
    return tempMatrix;
}

template<class T, int row, int col>
Matrix<T, row, col> Matrix<T, row, col>::operator+(Matrix<T, row, col>& matrix2)
{
    Matrix<T, row, col> tempMatrix;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            {
                tempMatrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];
            }
    return tempMatrix;
}

template<class T, int row, int col>
Matrix<T, row, col> Matrix<T, row, col>::operator*(T variable)
{
    Matrix<T, row, col> tempMatrix;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            {
                tempMatrix[i][j] = matrix[i][j] * variable;
            }
    return tempMatrix;
}

template<class T, int row, int col>
Matrix<T, row, col> operator*(T variable, Matrix<T, row, col>& matrix2)
{
    Matrix<T, row, col> tempMatrix;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            {
                tempMatrix[i][j] = matrix2[i][j] * variable;
            }

    return tempMatrix;
}

int main()
{
    Matrix<int, 3, 2> matrix1;
    Matrix<int, 3, 2> matrix2;
    Matrix<int, 3, 2> matrix3;

    
    //matrix3 = matrix1.matrixTranspose();
    matrix3 = matrix1 * 8;
    for(int i = 0; i < matrix2.matrixRow; ++i)
        for(int j = 0; j < matrix2.matrixCol; ++j)
        {
            std::cout << matrix2[i][j] << std::endl;
        }


    for(int i = 0; i < matrix3.matrixRow; ++i)
        for(int j = 0; j < matrix3.matrixCol; ++j)
        {
            std::cout << matrix3[i][j] << std::endl;
        }


    //matrix1*matrix2;

    /*for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 4; ++j)
            {
                std::cout << matrix_3[i][j] << std::endl;
            }
    */
    return 0;
}
