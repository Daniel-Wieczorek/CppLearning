#include <iostream>
#include <string>

// example implementation of std::array using templates:

template<typename T, int N>
class Array
{
    private:
    int size {N};
    T values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &ar)
    {
        os << "[";
        for(const auto &var: ar.values)
            os << var << " ";
        os << "]" << std::endl;
        return os;
    }

public:
    Array() = default;
    Array(T initValue)
    {
        for(auto &item: values)
            item = initValue;
    }

    void fill(T value)
    {
        for(auto &item: values)
            item = value;
    }

    int get_size() const
    {
        return size;
    }

    // overload subscript operator here:
    T &operator[](int index)
    {
        return values[index];
    }

};


int main()
{

    Array<int,10> numbers;
    std::cout << "The size of num is: " << numbers.get_size() << std::endl;
    std::cout << numbers << std::endl; // garbage data

    numbers.fill(0);
    std::cout << "The size of num is: " << numbers.get_size() << std::endl;
    std::cout << numbers << std::endl;

    numbers.fill(66);
    std::cout << "The size of num is: " << numbers.get_size() << std::endl;
    std::cout << numbers << std::endl;

    numbers[0] = 1000; // nums.operator[](0) --> this will be called in reality!
    numbers[3] = 2000;
    std::cout << numbers << std::endl;

    Array<std::string, 10> myStrings{"Daniel"};
    std::cout << myStrings << std::endl;

    return 0;
}