#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

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
    std::atomic<int> count{0};
    const int ITERATIONS{1000000};

    auto callable = [&]()
    {
        for(int i=0;i<ITERATIONS;i++)
        {
            count++;
        } };

    std::thread t1(callable);
    std::thread t2(callable);

    t1.join();
    t2.join();

    std::cout << count << std::endl;

    return 0;
}