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
                       std::cout << "Acquiring lock ...\n";
                       std::unique_lock<std::mutex> lock(mtx);                       // try to acquire the lock here
                       ready = true;                                                 // when it gets lock change variable value
                       lock.unlock();                                                // and unlock the lock
                       condition_var.notify_one();                                   // notify ONE thread after unlocking lock.
                   });

    std::cout << "Main lock ON\n";
    std::unique_lock<std::mutex> main_lock(mtx);
    
    std::cout << "Condvar waiting...\n";
    condition_var.wait(main_lock, [&]()
                       { return ready; }); // Instead of while loop second condition will do the job
    std::cout << "Condvar end\n";
    
    std::cout << "Ready\n";
    t1.join();

    return 0;
}