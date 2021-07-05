#include <exception>
#include <iostream>
#include <thread>
#include <chrono>

// Передача параметров в поток


void DoWork(int var1, int var2, std::string massage)
{
    std::cout << massage << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "===========\t" << "DoWork STARTED\t=========" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    std::cout << "var1 + var2 = " << var1 + var2 << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "===========\t" << "DoWork STOPPED\t=========" << std::endl;
}

int main()
{
    std::thread thread2(DoWork, 2, 3, "Our threads are ready to work!");

    for(size_t i = 0; true; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tmain"
             " works\t" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if(i == 28)
            break;
    }

    thread2.join();

    return 0;
}

