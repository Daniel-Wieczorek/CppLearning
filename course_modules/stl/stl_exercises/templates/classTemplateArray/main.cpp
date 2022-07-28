#include <string>
#include <vector>
#include <iostream>

template <typename T,int N>
class Array
{
private:
    int size {N};
    T values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) 
    {
        os << "[";
        for (const auto &var: arr.values)
        os << var <<" ";
        os << "]" << std::endl;
    }
public:
    Array() = default;
    Array(T initValue)
    {
        for (auto &item : values)
            item = initValue;
        
    }
    void fill(T val)
    {
        for(auto &item: values)
            item = val;
    }
    int get_size() const
    {
        return size;
    }

    //overload subsript operator for easy use
    T &operator[](int index)
    {
        return values[index];
    }
};


int main()
{
    Array<int,5> nums;
    std::cout << "The size of nums is " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;
    
    nums.fill(10);
    std::cout << "The size of nums is " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    Array<int,100> nums2 {1};
    std::cout << "The size of nums is " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string,10> stringObject (std::string{"Dany"});
    std::cout << "The size of nums is " << stringObject.get_size() << std::endl;
    std::cout << stringObject << std::endl;

    stringObject[0] = std::string("Frank");
    std::cout << stringObject << std::endl;

    return 0;
}