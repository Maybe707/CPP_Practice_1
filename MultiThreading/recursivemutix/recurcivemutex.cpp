#include <iostream>
#include <mutex>
#include <ostream>
#include <thread>

/*
 * Multithreading programming
 *
 *       recurcive mutex
 *
 *       recurcive block
 *
 *      safety of devided data
 *
 *  threads sinhronization
 */

std::recursive_mutex mtxRec;

void Foo(int value)
{
    mtxRec.lock();
    std::cout << value << " " << std::flush;

    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    if(value <= 1)
    {
        std::cout << std::endl;
        mtxRec.unlock();
        return;
    }

    value--;
    Foo(value);
    mtxRec.unlock();
}

int main()
{
    std::thread thread1(Foo, 10);
    std::thread thread2(Foo, 10);

    thread1.join();
    thread2.join();

    return 0;
}

