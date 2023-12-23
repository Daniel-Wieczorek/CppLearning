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

int main()
{
    std::future<int> future = std::async(std::launch::async, []()
                                         {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return 8; });

    std::cout << "Main thread starts...\n";
    std::future_status status;

    // specify how big timeout should be:
    auto timeout_duration = std::chrono::seconds(4);

    do
    {
        status = future.wait_for(timeout_duration);
        switch (status)
        {
        case std::future_status::timeout:
            std::cout << "timeout\n";
            break;
        case std::future_status::ready:
            std::cout << "ready!\n";
            break;
        }
    } while (status != std::future_status::ready);

    std::cout << "result is " << future.get() << '\n';
}