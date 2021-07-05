#include <initializer_list>
#include <iostream>
#include <iterator>
#include <pthread.h>
#include <cassert>
#include <vector>

template<class T, int row, int col>
class Tensor
{
public:
    int tensorRow;
    int tensorCol;
    T tensor[row][col];
    Tensor() : tensorRow(row), tensorCol(col)
    {
    }

    Tensor(std::initializer_list<std::initializer_list<T>> list)
    {
        *this = list;
    }

    Tensor<T, col, row> tensorTranspose()
        {
            Tensor<T, col, row> tempTranceponentTensor;
            for(int i = 0; i < row; ++i)
                for(int j = 0; j < col; ++j)
                {
                    tempTranceponentTensor[j][i] = tensor[i][j];
                }
            return tempTranceponentTensor;
        }

    template<class T2, int row2, int col2>
    Tensor<T, row, col2> operator*(Tensor<T2, row2, col2>& tensor2);

    T operator()(const int index1, const int index2);
    T* operator[](const int index);
    Tensor<T, row, col> operator-(Tensor<T, row, col>& tensor2);
    Tensor<T, row, col> operator+(Tensor<T, row, col>& tensor2);
    Tensor<T, row, col> operator*(T variable);
    friend Tensor<T, row, col> operator*(T variable, Tensor<T, row, col>& tensor2);
    void operator=(std::initializer_list<std::initializer_list<T>> list);
};

template<class T, int row, int col>
template<typename T2, int row2, int col2>
Tensor<T, row, col2> Tensor<T, row, col>::operator*(Tensor<T2, row2, col2>& tensor2)
{
    assert(col == row2 && "Col of first tensor dont equal row of second tensor");
    Tensor<T, row, col2> tempTensor;
  for (int x = 0; x < row; ++x)
    for (int z = 0; z < col2; ++z) {
        tempTensor.tensor[x][z] = 0;
    }
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col2; ++j)
            for(int l = 0; l < col; ++l)
            {
                tempTensor.tensor[i][j] += tensor[i][l] * tensor2.tensor[l][j];
            }
    /*for(int n = 0; n < row; ++n)
        for(int m = 0; m < col2; ++m)
        {
            std::cout << tempTensor.tensor[n][m] << std::endl;
        }
    */
    return tempTensor;
}

template <class T, int row, int col>
T Tensor<T, row, col>::operator()(const int index1, const int index2)
{
    return tensor[index1][index2];
}

template <class T, int row, int col>
T* Tensor<T, row, col>::operator[](const int index)
{
    return tensor[index];
}

template<class T, int row, int col>
Tensor<T, row, col> Tensor<T, row, col>::operator-(Tensor<T, row, col>& tensor2)
{
    //assert(tensor2.tensor == col && tensor2.tensorRow == row && "Sizes of tensor dont equal");
    Tensor<T, row, col> tempTensor;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            {
                tempTensor[i][j] = tensor[i][j] - tensor2.tensor[i][j];
            }
    return tempTensor;
}

template<class T, int row, int col>
Tensor<T, row, col> Tensor<T, row, col>::operator+(Tensor<T, row, col>& tensor2)
{
    //assert(tensor2.tensor == col && tensor2.tensorRow == row && "Sizes of tensor dont equal");
    Tensor<T, row, col> tempTensor;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            {
                tempTensor[i][j] = tensor[i][j] + tensor2.tensor[i][j];
            }
    return tempTensor;
}

template<class T, int row, int col>
Tensor<T, row, col> Tensor<T, row, col>::operator*(T variable)
{
    Tensor<T, row, col> tempTensor;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            {
                tempTensor[i][j] = tensor[i][j] * variable;
            }
    return tempTensor;
}

template<class T, int row, int col>
Tensor<T, row, col> operator*(T variable, Tensor<T, row, col>& tensor2)
{
    Tensor<T, row, col> tempTensor;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            {
                tempTensor[i][j] = tensor2[i][j] * variable;
            }

    return tempTensor;
}

template <class T, int row, int col>
std::ostream& operator<<(std::ostream &ostream,
                               Tensor<T, row, col>& tensor)
{
    /*for (int (&array)[col] : tensor.tensor)
        for(int n : array)
            {
                ostream << n << " ";
            }*/
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
        {
            ostream << tensor.tensor[i][j] << " ";
        }

    return ostream;
}

template <typename X, int row, int col>
Tensor<X, 1, col> cutFunction(Tensor<X, row, col>& tensor, int iteration)
{
    Tensor<X, 1, col> tempTensor;
    for(int i = 0; i < col; ++i)
    {
        tempTensor[0][i] = tensor.tensor[iteration][i];
    }
    return tempTensor;
}

template <class T, int row, int col>
void Tensor<T, row, col>::operator=(std::initializer_list<std::initializer_list<T>> list)
{
    typename std::initializer_list<std::initializer_list<T>>::const_iterator iterator;
    typename std::initializer_list<T>::const_iterator iterator2;
    iterator = list.begin();
    iterator2 = iterator->begin();
    for(int i = 0; i < row; ++i)
    {
        iterator2 = iterator->begin();
        ++iterator;
        for(int j = 0; j < col; ++j)
        {
            tensor[i][j] = *iterator2;
            ++iterator2;
        }
    }
}

/*template<class T, int row, int col>
void Tensor<T, row, col>::operator=(std::initializer_list<T> list)
{
    typename std::initializer_list<T>::const_iterator iterator;
    iterator = list.begin();
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
        {
            tensor[i][j] = *iterator;
            ++iterator;
        }
}*/

// Return X if X > 0; else return 0
template <class T, int row, int col>
void relu(Tensor<T, row, col>& tensor)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
        {
            if(tensor[i][j] > 0)
                tensor[i][j] = tensor[i][j];
            else
                tensor[i][j] = 0;
        }
        //return (x > 0) * x;
}

// Return 1, if output > 0; else return 0
template<class T, int row, int col>
void relu2deriv(Tensor<T, row, col>& tensor, double* reluResult)
{

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
        {
            if(tensor[i][j] > 0)
                reluResult[j] = 1;
            else
                reluResult[j] = 0;
        }
}

double getRandomNumber(double min, double max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<double>(rand() * fraction * (max - min + 1) + min)-1;
}

template <class T, int row, int col>
void weightsGenerator(Tensor<T, row, col>& tensor)
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            tensor[i][j] = getRandomNumber(0.0, 1.0);
        }
    }
}
/*
void weightsGeneratorVector(double* weightsVector, int range)
{
    for(int i = 0; i < range; ++i)
    {
        weightsVector[i] = getRandomNumber(0.0, 1.0);
    }
}*/
