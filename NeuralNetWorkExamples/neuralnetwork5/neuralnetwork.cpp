#include <iostream>
#include <cmath>
#include <cassert>

double w_sum(double vector1[], double vector2[], int range1, int range2)
{
    assert(range1 == range2);
    double output = 0;
    for(int i = 0; i < range1; i++)
    {
        output += (vector1[i] * vector2[i]);
    }

    return output;
}

double* vect_mat_mul(double output[], double vect[], double matrix[3][3], int range1, int range2,
                                                        double(*pointer)(double[], double[],
                                                            int, int))
{
    assert(range1 == range2);
    for(int i = 0; i < range1; i++)
    {
        output[i] = (*pointer)(vect, matrix[i], range1, range2);
    }
    

    return output;
}

double* neural_network(double output[], double input[], double (*weights[2])[3][3], int range1, int range2,
                                            double*(*pointer2)(double[], double[], double[3][3],
                                                int, int,
                                               double(*)(double[], double[], int, int)))
{
    double* pred = nullptr;
    double* pred2 = nullptr;
    pred = (*pointer2)(output, input, *weights[0], range1, range2, w_sum); 
    double array[3] = {};
    array[0] = pred[0];
    array[1] = pred[1];
    array[2] = pred[2];
    pred = nullptr;
    pred2 = (*pointer2)(output, array, *weights[1], range1, range2, w_sum);
    return pred2;
}

int main()
{
    double weights[3][3] = {{0.1, 0.2, -0.1},
                           {-0.1, 0.1, 0.9},
                           {0.1, 0.4, 0.1}};

    double weights2[3][3] = {{0.3, 1.1, -0.3},
                             {0.1, 0.2, 0.0},
                             {0.0, 1.3, 0.1}};


    double (*point[2])[3][3] = {&weights, &weights2};

    double weightsTemp1[3][3] = {{0.0, 0.0, 0.0},
                           {0.0, 0.0, 0.0},
                           {0.0, 0.0, 0.0}};

    double weightsTemp2[3][3] = {{0.0, 0.0, 0.0},
                             {0.0, 0.0, 0.0},
                             {0.0, 0.0, 0.0}};


    double (*pointTemp[2])[3][3] = {&weightsTemp1, &weightsTemp2};



    int range1 = 3, range2 = 3;
       
    double toes[4] = {8.5, 9.5, 9.9, 9.0};
    double wlrec[4] = {0.65, 0.8, 0.8, 0.9};
    double nfans[4] = {1.2, 1.3, 0.5, 1.0};

    double output[] = {0, 0, 0};
    double outputTemp[] = {0, 0, 0};

    double input[3] = {toes[0], wlrec[0], nfans[0]};

    double stepAmount = 0.00001;

    int iterations = 100;

    int iterationCounter = 1;

    bool flag = true;
    
    std::cout << "Enter goal prediction: " << std::endl;
    double goalPrediction = 0.0;
    std::cin >> goalPrediction;

    while(flag)
    {
        neural_network(output, input, point, range1, range2, vect_mat_mul);
        double activationsSum = output[0] + output[1] + output[2];
        
        double error = (activationsSum - goalPrediction) * (activationsSum - goalPrediction);

        std::cout << "Iteration number: " << iterationCounter << std::endl;
        iterationCounter++;
        std::cout << "Error:" << error << " Prediction:" << activationsSum << std::endl;

        for(int a = 0; a < 3; a++)
        {
            for(int u = 0; u < 3; u++)
            {
                weightsTemp1[a][u] = weights[a][u];
            }
        }
        for(int s = 0; s < 3; s++)
        {
            for(int d = 0; d < 3; d++)
            {
                weightsTemp2[s][d] = weights2[s][d];
            }
        }

        for(int j = 0; j < 3; j++)
        {
            for(int v = 0; v < 3; v++)
            {
                weightsTemp1[j][v] -= stepAmount;
            }
        }
        for(int n = 0; n < 3; n++)
        {
            for(int m = 0; m < 3; m++)
            {
                weightsTemp2[n][m] -= stepAmount;
            }
        }
        neural_network(outputTemp, input, pointTemp, range1, range2, vect_mat_mul);
        double activationsSumUp = outputTemp[0] + outputTemp[1] + outputTemp[2];
        double downError = (activationsSumUp - goalPrediction) * (activationsSumUp - goalPrediction);

        for(int x = 0; x < 3; x++)
        {
            for(int w = 0; w < 3; w++)
            {
                weightsTemp1[x][w] += stepAmount;
            }
        }
        for(int z = 0; z < 3; z++)
        {
            for(int y = 0; y < 3; y++)
            {
                weightsTemp2[z][y] += stepAmount;
            }
        }
        neural_network(outputTemp, input, pointTemp, range1, range2, vect_mat_mul);
        double activationsSumDown = outputTemp[0] + outputTemp[1] + outputTemp[2];
        double upError = (activationsSumDown - goalPrediction) * (activationsSumDown - goalPrediction);

        if(downError < upError)
        {
            for(int j = 0; j < 3; j++)
                {
                    for(int v = 0; v < 3; v++)
                        {
                            weights[j][v] -= stepAmount;
                        }
                }
            for(int n = 0; n < 3; n++)
                {
                    for(int m = 0; m < 3; m++)
                        {
                            weights2[n][m] -= stepAmount;
                        }
                }
        } 

        if(downError > upError)
        {
            for(int j = 0; j < 3; j++)
                {
                    for(int v = 0; v < 3; v++)
                        {
                            weights[j][v] += stepAmount;
                        }
                }
            for(int n = 0; n < 3; n++)
                {
                    for(int m = 0; m < 3; m++)
                        {
                            weights2[n][m] += stepAmount;
                        }
                }
        }
        
        if(error < 0.0000001)
        {
            flag = false;
        }
    }
    
    std::cout << *(neural_network(output, input, point, range1, range2, vect_mat_mul)) << std::endl;
    
    std::cout << *(neural_network(output, input, point, range1, range2, vect_mat_mul)+1) << std::endl;

    std::cout << *(neural_network(output, input, point, range1, range2, vect_mat_mul)+2) << std::endl;
       
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << weights[i][j] << std::endl;
        }
    }

    for(int i = 0; i < 3; i++)
    {
       for(int j = 0; j < 3; j++)
       {
           std::cout << weights2[i][j] << std::endl;
       }
    }

    return 0;
}








    



