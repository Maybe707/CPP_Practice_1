#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"

/*
 * Multithreading programming
 *
 *        unique_lock
 *
 *      safety of devided data
 *
 *  threads sinhronization
 */

std::mutex mtx;

void Print(char ch)
{

    std::unique_lock<std::mutex> uniLock(mtx, std::defer_lock);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    uniLock.lock();

    for(int i = 0; i < 5; ++i)
    {
        for(int i = 0; i < 10; ++i)
        {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //uniLock.unlock();

    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main()
{
    SimpleTimer timer;

    std::thread thread1(Print, '*');
    std::thread thread2(Print, '#');
    thread1.join();
    thread2.join();

    return 0;
}

