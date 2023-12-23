#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <atomic>
#include <condition_variable>
#include <future>

int main()
{
    // number of threads in the same time:
    std::cout << std::thread::hardware_concurrency() << std::endl;
    return 0;
}