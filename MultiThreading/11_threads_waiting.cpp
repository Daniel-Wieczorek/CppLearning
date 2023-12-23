#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <atomic>

int main()
{
    std::atomic<bool> ready{false};

    std::thread t1([&]()
                   {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        ready = true; });

    std::cout << "Waiting to join\n";

    while (!ready)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        std::cout << "Waiting next 250ms...\n";
    }

    std::cout << "Ready\n";

    t1.join();
    return 0;
}