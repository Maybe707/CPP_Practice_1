#include <iostream>
#include <boost/array.hpp>
#include <mlpack/core.hpp>
#include <tensorflow/c/c_api.h>
#include <torch/torch.h>

int main()
{
    torch::Tensor tensor = torch::rand({5, 7});
    boost::array<int, 4> array = {{1, 2, 3, 4}};
}

