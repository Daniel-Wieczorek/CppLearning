#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

void work()
{
    std::cout << "Thread starts\n";
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Loop: " << i << std::endl;
    }
}

int main()
{
    int count{0};
    const int ITERATIONS{1000000};
    std::mutex mtx;

    auto func = [&]()
    {
        for (int i = 0; i < ITERATIONS; i++)
        {
            // Critical section starts with lock()
            mtx.lock(); // the problem is if we will have exception then unlock() will never happen - better to use lock_guard()
            count++;
            mtx.unlock();
            // Critical section ends with unlock()
        }
    };

    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    std::cout << count << std::endl;
    return 0;
}