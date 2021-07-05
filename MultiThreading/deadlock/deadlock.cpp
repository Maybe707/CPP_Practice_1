#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"

/*
 * Multithreading programming
 *
 *        deadlock
 *
 *      safety of devided data
 *
 *  threads sinhronization
 */

std::mutex mtx1;
std::mutex mtx2;

void Print()
{
    mtx1.lock();  

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    mtx2.lock();

    for(int i = 0; i < 5; ++i)
    {
        for(int i = 0; i < 10; ++i)
        {
            std::cout << '*';
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    mtx1.unlock();

    mtx2.unlock();
}

void Print2()
{
    mtx1.lock();  

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    mtx2.lock();

    for(int i = 0; i < 5; ++i)
    {
        for(int i = 0; i < 10; ++i)
        {
            std::cout << '#';
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    mtx1.unlock();

    mtx2.unlock();
}

int main()
{
    SimpleTimer timer;

    std::thread thread1(Print);
    std::thread thread2(Print2); 

    thread1.join();
    thread2.join(); 
    
    //Print('*');
    //Print('#');
    //Print('@');

    return 0;
}

