#include <iostream>
#include <thread>
#include <chrono>

void DoWork()
{
    for(size_t i = 0; i < 10; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWork" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
    

int main()
{
    std::thread th(DoWork);
    std::thread th2(DoWork);

    for(size_t i = 0; i < 10; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tmain" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    
    th.join();
    th2.join();

    return 0;
}
