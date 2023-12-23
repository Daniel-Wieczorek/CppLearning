#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

const int ITERATIONS{1000000};

void work(int &count, std::mutex &mtx)
{
    std::cout << "Thread starts\n";
    for (int i = 0; i < ITERATIONS; i++)
    {
        // Critical section starts using RAII
        std::lock_guard<std::mutex> guard(mtx);
        count++;
    }
}

int main()
{
    int count{0};
    std::mutex mtx;

    std::thread t1(work, std::ref(count), std::ref(mtx));
    std::thread t2(work, std::ref(count), std::ref(mtx));

    t1.join();
    t2.join();

    std::cout << count << std::endl;

    return 0;
}