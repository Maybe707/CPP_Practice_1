#include <iostream>

int main()
{
    double weight = -0.5;
    double goal_pred = 0.8;
    double input = 0.5;

    for(int i = 0; i < 20; i++)
    {
        double pred = 0.0;
        double error = 0.0;
        double direction_and_amount = 0.0;
        pred = input * weight;
        std::cout << "Clear error: " << (pred - goal_pred) << std::endl;
        error = (pred - goal_pred) * (pred - goal_pred);
        direction_and_amount = (pred - goal_pred)*input;
        std::cout << "Weight: " << weight << std::endl;
        weight = weight - direction_and_amount;
        
        std::cout << "Error:" << error << " Prediction:" << pred << " Weight:" << weight << std::endl;
    }

    return 0;
}
        
        
