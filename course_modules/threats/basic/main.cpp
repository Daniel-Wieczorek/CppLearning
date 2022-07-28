#include <iostream>
#include <thread>
#include <pthread.h>

int count{ 0 }; // Evil but only for learing!
const int ITERATORS{ 1000000 };

void work()
{
    for (int i = 0;i<ITERATORS;i++)
        std::cout<<"Loop: "<<i<<std::endl;
}

int main()
{

    std::thread t1(work);

    return 0;
}