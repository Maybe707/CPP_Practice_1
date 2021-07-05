#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"

/*
 * Multithreading programming
 *
 *        lockguard
 *
 *      safety of devided data
 *
 *  threads sinhronization
 */

std::mutex mtx;

void Print(char ch)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    {
        std::lock_guard<std::mutex> guard(mtx);
        for(int i = 0; i < 5; ++i)
        {
            for(int i = 0; i < 10; ++i)
            {
                std::cout << ch;
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main()
{
    SimpleTimer timer;

    std::thread thread1(Print, '*');
    std::thread thread2(Print, '#'); 
    std::thread thread3(Print, '@'); 

    thread1.join();
    thread2.join(); 
    thread3.join(); 
    
    //Print('*');
    //Print('#');
    //Print('@');

    return 0;
}

