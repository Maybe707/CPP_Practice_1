#include <iostream>
#include <cassert>
#include <cmath>

double w_sum(int indexInput, int indexWeights, double value1[], double value2[])
{
    assert(indexInput == indexWeights);
    double output = 0;

    for(int i = 0; i < indexInput; ++i)
    {
        output += (value1[i] * value2[i]);
    }

    return output;
}

double neural_network(int indexInput, int indexWeights, double input[],double weights[], double(*pointer)(int, int, double[], double[]))
{
    double pred;
    pred = pointer(indexInput, indexWeights, input, weights);
    return pred;
}

double* ele_mul(int indexOutput, int indexInput, double number, double vector[], double output[])
{
    assert(indexOutput == indexInput);
    
    for(int i = 0; i < indexInput; ++i)
    {
        output[i] = number * vector[i];
    }

    return output;
}

int main()
{
    constexpr int indexWeights = 3, index2 = 4, indexInput = 3, indexOutput = 3;
    double weights[indexWeights] = {0.1, 0.2, -0.1};

    double toes[index2] = {8.5, 9.5, 9.9, 9.0};
    double wlrec[index2] = {0.65, 0.8, 0.8, 0.9};
    double nfans[index2] = {1.2, 1.3, 0.5, 1.0};

    double win_or_lose_binary[index2] = {1, 1, 0, 1};
    double true1 = win_or_lose_binary[0];

    double input[indexInput] = {toes[0], wlrec[0], nfans[0]};

    double pred;
    pred = neural_network(indexInput, indexWeights, input, weights, w_sum);
    double error = (pred - true1) * (pred - true1);
    double delta = pred - true1;
    
    double output[indexOutput] = {0, 0 , 0};
    double *weight_deltas = ele_mul(indexOutput, indexInput, delta, input, output);

    double alpha = 0.1;

    for(int i = 0; i < indexWeights; ++i)
    {
        weights[i] -= alpha * weight_deltas[i];
    }

    std::cout << "Weights: " << weights[0] << " " << weights[1] << " " << weights[2] << std::endl;
    std::cout << "Weights Deltas: " << weight_deltas[0] << " " << weight_deltas[1] << " " << weight_deltas[2] << std::endl;

    return 0;
}












