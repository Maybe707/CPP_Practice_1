#include <iostream>
#include <thread>
#include <chrono>

// Получение результатов работы функции из потока с помощью лямбды.

int Sum(int var1, int var2)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    std::cout << "ID thread = " << std::this_thread::get_id() << 
        " =============\tSum STARTED \t=============" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    std::cout << "ID thread = " << std::this_thread::get_id() << 
        " ============\tSum STOPPED \t============" << std::endl;
    return var1 + var2;
}

int main()
{
    int result;
    std::thread threadSum([&result]()
    { 
         result = Sum(2, 5); 
    });

    for(size_t i = 1; i <= 10; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << 
            "\tmain works\t" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    threadSum.join();
    std::cout << "Sum Result = " << result << std::endl;

    return 0;
}
