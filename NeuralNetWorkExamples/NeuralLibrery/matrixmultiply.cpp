#include <iostream>
#include <cmath>
#include <random>

double* vectMatrixMultiply(const int matrixRow, const int matrixCol, double* vectorReturn, 
        double* vector, double* matrix)
{
    for(int i = 0; i < matrixCol; ++i) 
    {
        for(int j = 0; j < matrixRow; ++j)
        {
            double temp = 0;
            temp = vector[j]*matrix[i+(j*matrixCol)];
            if(temp < 0.001)
                temp = 0;
            vectorReturn[i] += temp;
            
        }
    } 
    return vectorReturn; 
} 

int main(int argc, char* argv[])
{
    srand(static_cast<unsigned int>(time(0)));

    const int index1 = 4;
    const int index2 = 3;
    const int index3 = 1;
    const int indexMultiply = index1 * index2;
    double streetLights[index2][index1] = { {1, 2, 5, 3},
                            {2, 1, 1, 5},
                            {2, 3, 7, 5}};

    double walk_vs_stop[4] = {1, 1, 0, 0};

    double alpha = 2.0;
    double hidden_size = 4; 
    double layer_0[index2] = {2, 3, 5};
    double layer_1[index1] = {3, 5, 3};
    for(int i = 0; i < 4; ++i)
        layer_1[i] = 0;
    double* pointerLayer_1;

    double weights_0_1[index2][index1];
    double weights_1_2[index3][index1]; 

    for(int i = 0; i < 60; ++i)
    {
        double layer_2_error = 0;
        for(int j = 0; j < 1; ++j)
        {
            pointerLayer_1 = vectMatrixMultiply(index2, index1, layer_1, layer_0, (double*)streetLights); 
        }
    }

    std::cout << layer_1[0] << std::endl;
    std::cout << layer_1[1] << std::endl;
    std::cout << layer_1[2] << std::endl;
    std::cout << layer_1[3] << std::endl;
}




















