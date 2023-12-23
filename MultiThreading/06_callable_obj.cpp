#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <atomic>
#include <mutex>

const int ITERATIONS{1000000};

class App
{

private:
    int count{0};
    std::mutex mtx;

public:
    // callable object
    void operator()()
    {
        std::cout << "Hello from App class" << std::endl;
        for (int i = 0; i < ITERATIONS; i++)
        {
            // Critical section starts using RAII
            std::lock_guard<std::mutex> guard(mtx);
            count++;
        }
    }

    int getCount() { return count; }
};

int main()
{
    App obj;

    std::thread t1(std::ref(obj));
    std::thread t2(std::ref(obj));

    t1.join();
    t2.join();

    std::cout << obj.getCount() << std::endl;
    std::cout << "Hello World" << std::endl;

    return 0;
}