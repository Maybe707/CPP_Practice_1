#include <iostream>
#include <cmath>
#include <ostream>
#include <random>

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

double* vectMatrixMultiply(double* vectorReturn, double* vector,
        double* matrix, int matrixRow, int matrixCol)
{
    for(int i = 0; i < matrixCol; ++i)
    {
        for(int j = 0; j < matrixRow; ++j)
        {
            double temp = 0;
            temp = vector[j]*matrix[i+(j*matrixCol)];
            vectorReturn[j] += temp;
        }
    }
    return vectorReturn;
}
/*
void vectMultiply(double* vectorReturn, double* vector1, double* vector2, const int vectRange)
{
    for(int i = 0; i < vectRange; ++i)
    {
        vectorReturn[i] = vector1[i]*vector2[i];
    }
}*/

double layer_Error(double layer2, double* walk_vs_stop, double error, int iteration)
{
        error += (layer2 - walk_vs_stop[iteration])*(layer2 - walk_vs_stop[iteration]);
    return error;
}

double layer_2_Delta(double layer2, double* walk_vs_stop, double delta, int iteration)
{
    delta = (layer2 - walk_vs_stop[iteration]);
    return  delta;
}

/*void transponentMatrix(double** baseMatrix, double** resultMatrix, int matrixRange)
{
    for(int i = 0; i < matrixRange; ++i)
    {
        resultMatrix[1][i] = baseMatrix[i][1];
    }
}*/

void transponentMatrix(double** baseMatrix, double** resultMatrix, int matrixRange,
                        int count)
{
    int iteration = 0;
    do
    {
        for(int i = 0; i < matrixRange; ++i)
        {
            resultMatrix[iteration][i] = baseMatrix[i][iteration];
            std::cout << resultMatrix[iteration][i];
        }
       ++iteration;
    }while (iteration < count);
}

void transponentMatrix2(double** layer_1_T, double* layer_1, int matrixRange,
                        int count)
{
    int iteration = 0;
    do
    {
        for(int i = 0; i < matrixRange; ++i)
        {
            layer_1_T[i][iteration] = layer_1[i];
        }
        ++iteration;
    }while (iteration < count);
}

void transponentMatrix3(double** layer_0_T, double* layer_0, int matrixRange,
                        int count)
{
    int iteration = 0;
    do
    {
        for(int i = 0; i < matrixRange; ++i)
        {
            layer_0_T[i][iteration] = layer_0[i];
        }
        ++iteration;
    }while (iteration < count);
}

void multiplyLayer_1_TandLayer_2_delta(double** layer_1_T, double layer_2_delta,
                                       double alpha, int matrixRange)
{
    for(int i = 0; i < matrixRange; ++i)
    {
        layer_1_T[i][0] = layer_1_T[i][0]*layer_2_delta*alpha;
    }
}

void multiplayerForOgromniKozhaniDrakon(double** pointerNaOgromnogoKozhanogoDrakona,
                                        double** layer_0_T, double* layer_1_delta)
{
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 3; ++j)
        {
            pointerNaOgromnogoKozhanogoDrakona[j][i] = layer_0_T[j][0] * layer_1_delta[i];
        }
}

void layer1deltaFunction(double** pointer2dMatrix1_2, double* relu2derivResult,
                            double* layer_1_delta, double layer_2_delta, int range)
{
    int variable = 0;
    for(int i = 0; i < range; ++i)
    {
        layer_1_delta[i] = pointer2dMatrix1_2[variable][i]*relu2derivResult[i]*layer_2_delta;
    }
}

void alphaMultiplayerOKD(double** pointerNaOgromnogoKozhanogoDrakona, double alpha)
{
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 4; ++j)
        {
            pointerNaOgromnogoKozhanogoDrakona[i][j] = pointerNaOgromnogoKozhanogoDrakona[i][j] * alpha;
        }
}

void weights_1_2Correction(double** pointer2dMatrixWeights_0_1, double** pointerNaOgromnogoKozhanogoDrakona)
{
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 4; ++j)
        {
            pointer2dMatrixWeights_0_1[i][j] = pointer2dMatrixWeights_0_1[i][j] - pointerNaOgromnogoKozhanogoDrakona[i][j];
        }
}

int main(int argc, char* argv[])
{
    srand(static_cast<unsigned int>(time(0)));

    const int index1 = 4;
   const int index2 = 3;
    const int index3 = 1;
    const int indexMultiply = index1 * index2;
    double streetLights[index1][index2] = { {1, 0, 1},
                                            {0, 1, 1},
                                            {0, 0, 1},
                                            {1, 1, 1} };

    double walk_vs_stop[4] = {1, 1, 0, 0};

    double alpha = 0.2;
    double hidden_size = 4;
    double layer_0[index2];
    double layer_0_T[index2][index3] = {{0.0}, {0.0}, {0.0}};
    double* ptrLayer_0_T[index2] = {layer_0_T[0], layer_0_T[1], layer_0_T[2]};
    double** pointerLayer_0_T = ptrLayer_0_T;
    double layer_1[index1];
    double layer_2[index1] = {0.0, 0.0, 0.0, 0.0};
    double layer_2_Result = 0;
    double Layer_2_Error = 0;
    double layer_2_delta = 0;
    double layer_1_delta = 0;
    double layer_1_deltaResult[index1] = {0.0, 0.0, 0.0, 0.0};
    double reluResult[index1] = {0.0, 0.0, 0.0, 0.0};
    double relu2derivResult[index1] = {0.0, 0.0, 0.0, 0.0};
    double resultMatrixW1_2[1][4] = {0.0, 0.0, 0.0, 0.0};
    double layer_1_T[4][1] = {{0.0}, {0.0}, {0.0}, {0.0}};
    double* ptrLayer_1_T[4] = {layer_1_T[0], layer_1_T[1], layer_1_T[2], layer_1_T[3]};
    double** pointerLayer_1_T = ptrLayer_1_T;
    double OgromniKozhaniDrakon[index2][index1] = {{0.0, 0.0, 0.0, 0.0},
                                                   {0.0, 0.0, 0.0, 0.0},
                                                   {0.0, 0.0, 0.0, 0.0}};
    double* ptrNaOgromnogoKozhanogoDrakona[3] = {OgromniKozhaniDrakon[0],
                                                 OgromniKozhaniDrakon[1],
                                                 OgromniKozhaniDrakon[2]};
    double** pointerNaOgromnogoKozhanogoDrakona = ptrNaOgromnogoKozhanogoDrakona;

    for(int i = 0; i < 4; ++i)
        layer_1[i] = 0;

    double weights_0_1[index2][index1];
    double weights_1_2[index1][index3];

    weightsGenerator((double*) weights_0_1, index2, index1);
    weightsGenerator((double*) weights_1_2, index1, index3);

    double* ptrMatrixWeights_0_1[3] = {weights_0_1[0], weights_0_1[1], weights_0_1[2]};
    double** pointerMatrixWeights_0_1 = ptrMatrixWeights_0_1;
    double* ptrMatrixW1_2[1] = {resultMatrixW1_2[0]};
    double** pointer2dMatrix1_2 = ptrMatrixW1_2;
    double* ptrMatrixWeight1_2[4] = {weights_1_2[0], weights_1_2[1],
                                    weights_1_2[2], weights_1_2[3]};
    double** pointer2dMatrixWeight1_2 = ptrMatrixWeight1_2;

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            std::cout << weights_0_1[i][j] << std::endl;
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        std::cout << weights_1_2[i][0];
    }

    /*for(int i = 0; i < 60; ++i)
    {
        double layer_2_error = 0;
        for(int j = 0; j < 1; ++j)
        {
            streetLightsCut(streetLights, layer_0, index2, j);
            vectMatrixMultiply(layer_1, layer_0, (double*) weights_0_1, 3, 4);
            relu(layer_1, index1);
        }
    }*/

    streetLightsCut((double*) streetLights, layer_0, index2, 0);
    std::cout << layer_0[0] << std::endl;
    std::cout << layer_0[1] << std::endl;
    std::cout << layer_0[2] << std::endl;
    vectMatrixMultiply(layer_1, layer_0, weights_0_1[0], 3, 4);
    relu(layer_1, index1);
    vectMatrixMultiply(layer_2, layer_1, weights_1_2[0], index1, index3);
    for(int i = 0; i < 4; ++i)
    {
       layer_2_Result += layer_2[i];
    }

    Layer_2_Error = layer_Error(layer_2_Result, walk_vs_stop, Layer_2_Error, 0);

    layer_2_delta = layer_2_Delta(layer_2_Result, walk_vs_stop, layer_2_delta, 0);
    transponentMatrix(pointer2dMatrixWeight1_2, pointer2dMatrix1_2, index1, index3);
    relu2deriv(relu2derivResult, layer_1, index1);
    layer1deltaFunction(pointer2dMatrix1_2, relu2derivResult, layer_1_deltaResult, layer_2_delta, index1);
    transponentMatrix2(pointerLayer_1_T, layer_1, index1, index3);
    multiplyLayer_1_TandLayer_2_delta(pointerLayer_1_T, layer_2_delta, alpha, index1);
    for(int i = 0; i < index1; ++i)
    {
        weights_1_2[i][0] = weights_1_2[i][0] - pointerLayer_1_T[i][0];
    }
    transponentMatrix3(pointerLayer_0_T, layer_0, index2, index3);
    multiplayerForOgromniKozhaniDrakon(pointerNaOgromnogoKozhanogoDrakona, pointerLayer_0_T,
                                       layer_1_deltaResult);
    alphaMultiplayerOKD(pointerNaOgromnogoKozhanogoDrakona, alpha);
    weights_1_2Correction(pointerMatrixWeights_0_1, pointerNaOgromnogoKozhanogoDrakona);

    std::cout << layer_1[0] << std::endl;
    std::cout << layer_1[1] << std::endl;
    std::cout << layer_1[2] << std::endl;
    std::cout << layer_1[3] << std::endl;
}
