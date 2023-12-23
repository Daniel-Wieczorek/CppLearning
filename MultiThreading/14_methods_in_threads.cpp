#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <atomic>
#include <condition_variable>

template <typename Type>
class BlockingQueue
{
private:
    /* data */
public:
    void push(Type element) { std::cout << "PUSH\n"; };

    Type pop() { std::cout << "POP\n"; };
};

int main()
{
    BlockingQueue<int> qu;

    std::thread t1(&BlockingQueue<int>::push, &qu, 7);
    std::thread t2(&BlockingQueue<int>::pop, &qu);

    t1.join();
    t2.join();

    return 0;
}