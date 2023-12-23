#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <mutex>
#include <future>

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
   
    std::promise<double> promise_val;

    auto do_calc = [&](int terms)
    {
        auto result = calculate_pi(terms);
        promise_val.set_value(result);
    };

    std::thread t1(do_calc, 10000000);
    std::future<double> future_val = promise_val.get_future();

    std::cout << std::setprecision(10) << future_val.get() << std::endl;
    t1.join();

    // cout << setprecision(15) << calculate_pi(1E8) << endl;
    return 0;
}