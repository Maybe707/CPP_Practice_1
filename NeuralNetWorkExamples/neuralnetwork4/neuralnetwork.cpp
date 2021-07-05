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

    int range1 = 3, range2 = 3;
       
    double toes[4] = {8.5, 9.5, 9.9, 9.0};
    double wlrec[4] = {0.65, 0.8, 0.8, 0.9};
    double nfans[4] = {1.2, 1.3, 0.5, 1.0};

    double output[] = {0, 0, 0};

    double input[3] = {toes[0], wlrec[0], nfans[0]};
    
    std::cout << *(neural_network(output, input, point, range1, range2, vect_mat_mul)) << std::endl;
    
    std::cout << *(neural_network(output, input, point, range1, range2, vect_mat_mul)+1) << std::endl;

    std::cout << *(neural_network(output, input, point, range1, range2, vect_mat_mul)+2) << std::endl;
    
    for(int i = 0; i < range1; i++)
    {
        std::cout << output[i] << std::endl;
    }

    return 0;
}








    



