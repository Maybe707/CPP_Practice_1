#include <iostream>
#include <cmath>
#include <iostream>
#include <random>
#include "mathlibrery.cpp"

// Return X if X > 0; else return 0
void relu(double* vector, int vectRange)
{
    for(int i = 0; i < vectRange; ++i)
    {
        if(vector[i] > 0)
            vector[i] = vector[i];
        else
            vector[i] = 0;
    }
    //return (x > 0) * x;
}

// Return 1, if output > 0; else return 0
void relu2deriv(double* reluResult, double* vector, int vectRange)
{
   for(int i = 0; i < vectRange; ++i)
      {
         if(vector[i] > 0)
            reluResult[i] = 1;
         else
            reluResult[i] = 0;
      }
}

double getRandomNumber(double min, double max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<double>(rand() * fraction * (max - min + 1) + min)-1;
}

void weightsGenerator(double* weights, int matrixRow, int matrixCol)
{
    for(int i = 0; i < matrixCol; ++i)
        {
            for(int j = 0; j < matrixRow; ++j)
                {
                    weights[i*matrixRow + j] = getRandomNumber(0.0, 1.0);
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

void streetLightsCut(double* streetLights, double* layer_0, int index2, int iteration)
{
    for(int i = 0; i < index2; ++i)
        {
            layer_0[i] = streetLights[(index2*iteration)+i];
        }
}

int main()
{
    Matrix<double, 3, 2> streetlights;

    Matrix<double, 1, 4> tempMatrix;
    Matrix<double, 4, 1> walk_vs_stop;


    return 0;
}
