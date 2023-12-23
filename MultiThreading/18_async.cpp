#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <atomic>
#include <condition_variable>
#include <future>

int work(int id)
{
    std::cout << "Thread starts\n";
    for(int i =0; i<10;i++)
    {
        std::cout << "Loop id: " << id << " val: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return 100;
}

int main()
{
    std::future<int> f1 = std::async(std::launch::async, work, 1); // without std::future<int> f1  it will be syncheonous -> desctrucotr of std::async will block until finish. With assigning to future it is really async

    std::cout << f1.get() << std::endl;
    std::cout << "\n Main thread END \n " << std::endl;

    return 0;
}