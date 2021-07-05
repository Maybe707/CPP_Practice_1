#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"

/*
 * Multithreading programming
 *
 *        mutex
 *
 *      safety of devided data
 *
 *  threads sinhronization
 */

std::mutex mtx;

void Print()
{

    //mtx.lock();
    int sum = 0; 
    int array[1000000]; 

    for(int i = 0; i < 500000; ++i)
    {
            array[i] += i;
    }
    for(int i = 0; i < 500000; ++i)
    {
            sum += array[i];
    }
    std::cout << sum << std::endl; 
    std::cout << std::endl;

    //mtx.unlock();

}

int main()
{
    SimpleTimer timer;

    std::thread thread1(Print);
    std::thread thread2(Print); 
    std::thread thread3(Print); 
    std::thread thread4(Print); 

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    
    //Print('*');
    //Print('#');
    //Print('@');

    return 0;
}

