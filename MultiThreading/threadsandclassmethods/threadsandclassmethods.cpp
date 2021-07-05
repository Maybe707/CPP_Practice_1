#include <iostream>
#include <thread>
#include <chrono>

class SubThread
{
public:
    void DoWork()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        std::cout << "ID thread = " << std::this_thread::get_id() << 
            " ==========\tDoWork STARTED \t============= " << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(5000));


        std::cout << "ID thread = " << std::this_thread::get_id() << 
            " ==========\tDoWork STOPPED \t============= " << std::endl;
    }

    void DoWork2(int var)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        std::cout << "ID thread = " << std::this_thread::get_id() << 
            " ==========\tDoWork2 STARTED \t============= " << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        std::cout << "DoWork2 parameter value\t" << var << std::endl;

        std::cout << "ID thread = " << std::this_thread::get_id() << 
            " ==========\tDoWork2 STOPPED \t============= " << std::endl;
    }

    int Sum(int var1, int var2)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        std::cout << "ID thread = " << std::this_thread::get_id() << 
            " ==========\tSum STARTED \t============= " << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        std::cout << "ID thread = " << std::this_thread::get_id() << 
            " ==========\tSum STOPPED \t============= " << std::endl;
        return var1 + var2;
    } 
};

int main()
{
    //int result = 0;
    SubThread objThread;

    std::thread thread2(&SubThread::DoWork2, objThread, 5);
    /*std::thread thread2([&]()
            {
                result = objThread.Sum(2, 5);
            });*/

    for(size_t i = 1; i <= 10; ++i)
    {
        std::cout << "ID thread = " << std::this_thread::get_id() << 
            "\tmain works\t" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    thread2.join();
    //std::cout << "RESULT\t" << result << std::endl;

    return 0;
}
