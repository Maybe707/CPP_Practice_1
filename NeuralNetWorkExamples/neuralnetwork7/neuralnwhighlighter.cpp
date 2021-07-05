#include <iostream>
#include <cmath>
#include <cassert>

double* func(double input[], double streetlughts[6][3], int index)
{
    for(int i = 0; i < 3; ++i)
    {
        input[i] = streetlughts[index][i];
    }
    
    return input;
}

double func2(double input[], double weights[], double inputTemp[])
{
    double prediction = 0;

    for(int i = 0; i < 3; ++i)
    {
        inputTemp[i] = input[i];
    }

    for(int i = 0; i < 3; ++i)
    {
        inputTemp[i] = input[i] * weights[i];
        prediction += inputTemp[i];
    }

    return prediction;
}

double* func3(double input[], int index, double multiply, double inputTemp[])
{
    for(int i = 0; i < 3; ++i)
    {
        inputTemp[i] = input[i];
    }

    for(int i = 0; i < index; ++i)
    {
        inputTemp[i] = input[i] * multiply;
    }

    return inputTemp;
}

double* func4(double input[], double weights[])
{
    for(int i = 0; i < 3; ++i)
    {
        weights[i] = weights[i] - input[i];
    }

    return weights;
}
        
int main()
{
    double indexW = 3, indexSL = 6, indexWVS = 6;
    double weights[3] = {0.5, 0.48, -0.7};
    double alpha = 0.1;

    double streetlughts[6][3] = { {1, 0, 1},
                            {0, 1, 1},
                            {0, 0, 1},
                            {1, 1, 1},
                            {0, 1, 1},
                            {1, 0, 1} };
    
    double walk_vs_stop[6] = {0, 1, 0, 1, 1, 0};

    double input[3] = {};
    double inputTemp[3] = {};
    input[0] = streetlughts[0][0];
    input[1] = streetlughts[0][1];
    input[2] = streetlughts[0][2];

    double goal_prediction = walk_vs_stop[0];
    double prediction = 0;

    double* inputPointer = inputTemp;
    double* weightsPointer = weights;
    double error = 0;
    double delta = 0;

    for(int i = 0; i < 40; ++i)
    {
        double error_for_all_lights = 0;
        for(int j = 0; j < indexWVS; ++j)
        {
            inputPointer = func(input, streetlughts, j);
            goal_prediction = walk_vs_stop[j];

            prediction = func2(inputPointer, weights, inputTemp);

            error = (goal_prediction - prediction) * (goal_prediction - prediction);

            error_for_all_lights += error;

            delta = prediction - goal_prediction;
            inputPointer = func3(inputPointer, indexW, delta, inputTemp);
            inputPointer = func3(inputPointer, indexW, alpha, inputTemp);
            weightsPointer = func4(inputPointer, weights);

            std::cout << "Prediction: " << prediction << std::endl;
        }
        std::cout << "Iteration: " << i+1 << std::endl;
        std::cout << "Error: " << error_for_all_lights << std::endl;
        std::cout << "Weights: " << weights[0] << " " << weights[1] << " " <<
            weights[2] << std::endl;
    }

    return 0;
}

























