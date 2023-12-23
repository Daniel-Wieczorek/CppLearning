#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <atomic>
#include <condition_variable>

int main()
{
    bool ready{false};
    std::mutex mtx;
    std::condition_variable condition_var; // mechanism to work with threads.

    std::thread t1([&]()
                   {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // sleep for 2s
        std::unique_lock<std::mutex> lock(mtx); // try to acquire the lock here
        ready = true; // when it gets lock change variable value
        lock.unlock(); // and unlock the lock
        condition_var.notify_one(); // notify ONE thread after unlocking lock.
        });

    std::cout << "Waiting to join\n";

    std::unique_lock<std::mutex> main_lock(mtx);

    while (!ready)
    {
        condition_var.wait(main_lock); // it will release the lock for `mtx` from main_lock and waits for `notify_one()`
        std::cout << "Waiting...\n";
    }

    std::cout << "Ready\n";

    t1.join();
    return 0;
}