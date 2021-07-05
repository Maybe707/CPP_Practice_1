#include <functional>
#include <iostream>
#include <thread>
#include <chrono>

void DoWork(int &var1)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    std::cout << "ID thread = " << std::this_thread::get_id() <<  " =============\tDoWork STARTED \t==========" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    var1 *= 2;

    std::cout << "ID thread = " << std::this_thread::get_id() << " ===============\tDoWork STOPPED \t===========" << std::endl;
}

int main()
{
    int value = 5;

    std::thread thread2(DoWork, std::ref(value));
    //thread2.detach();

    for(size_t i = 0; i < 10; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << 
            "\tmain works\t" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    thread2.join();
    std::cout << value << std::endl;

    return 0;
}
