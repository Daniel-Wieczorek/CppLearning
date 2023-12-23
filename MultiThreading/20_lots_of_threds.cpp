#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <atomic>
#include <condition_variable>
#include <future>
#include <mutex>

std::mutex g_mtx;

int work(int id)
{
    
    std::unique_lock<std::mutex> lock(g_mtx);
    std::cout << "Thread id: " << id << std::endl;
    lock.unlock();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    return 100;
}

int main()
{
    std::vector<std::shared_future<int>> futures;

    for (int i = 0; i < std::thread::hardware_concurrency(); i++)
    {
        std::shared_future<int> f = std::async(std::launch::async, work, i);
        futures.push_back(f);
    }

    return 0;
}