#include <functional>
#include <iostream>

class TensorInt
{
    int Row;
    int** tensor = new int*[Row];
public:
    TensorInt(const int row, const int col) : Row(row)
    {
        for(int i = 0; i < row; ++i)
            tensor[i] = new int[col];
    }

    ~TensorInt()
    {
        for(int i = 0; i < Row; ++i)
            delete [] tensor[i];
        delete [] tensor;
    }

    int** getTensor()
    {
        return tensor;
    }

    int* operator[](const int index)
    {
        return tensor[index];
    }
};

int main()
{
    int value = 100;
    int value2 = 200;
    int value3 = value + value2;
    TensorInt tensor(10, 20);
    int** Pointer = tensor.getTensor();
    Pointer[2][2] = 1000;
    std::cout << Pointer[2][2] << std::endl;

    tensor[2][2] = 40;
    std::cout << tensor[2][2] << std::endl;

    return 0;
}
