#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <mutex>
#include <future>
#include <exception>

using namespace std;

double calculate_pi(int terms)
{
    double sum = 0.0;

    for (int i = 0; i < terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }

    return sum * 4;
}

int main()
{
    /*
    std::promise -> set value of the operation and thats all
    std::future -> get value of that std::promise(d) operation

    It could be one concept but in Cpp it is separated - set
    and get are separate functions.

    future_val.get() is blocking and waits for promise_val.set_value()
    */

    std::packaged_task<double(int)> task1(calculate_pi);
    std::future<double> future_1_val = task1.get_future();

    std::thread t1(std::move(task1), 1E6);
    double result = future_1_val.get();
    std::cout << std::setprecision(10) << result << std::endl;

    t1.join();

    return 0;
}