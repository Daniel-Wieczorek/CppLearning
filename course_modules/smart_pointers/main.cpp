
#include <iostream>
#include <memory>
#include <vector>

class Test
{

private:
    int data;

public:
    Test() : data{0}
    {
        std::cout << "Test constructor for data: " << data << std::endl;
    }

    Test(int data) : data{data}
    {
        std::cout << "Test constructor for data: " << data << std::endl;
    }

    int get_data() const { return data; }

    ~Test() { std::cout << "Test desctructor for data: " << data << std::endl; }
};

void func(std::shared_ptr<Test> pointer)
{
    std::cout << "Use count in func: " << pointer.use_count() << std::endl;
}

int main()
{
    //======================== UNIQUE POINTER =============================================
    {
        std::cout << "\n==== UNIQUE POINTER ==== " << std::endl;
        std::unique_ptr<int> t0_ptr = std::make_unique<int>(500);
        std::cout << "Test pointer number one: " << *t0_ptr << std::endl;

        std::unique_ptr<Test> t1_ptr{new Test{1000}};                // 1st METHOD
        std::unique_ptr<Test> t2_ptr = std::make_unique<Test>(2000); // 2nd METHOD

        std::unique_ptr<Test> t3_ptr;
        // t3_ptr = t1_ptr -> error!
        t3_ptr = std::move(t1_ptr);

        if (!t1_ptr)
            std::cout << "t1_ptr is nullptr" << std::endl;
    }
    //======================== SHARED POINTER =============================================
    {
        std::cout << "\n==== SHARED POINTER ==== " << std::endl;
        std::shared_ptr<int> p0_ptr{new int{300}};
        std::cout << "Use count: " << p0_ptr.use_count() << std::endl;

        std::shared_ptr<int> p2_ptr{p0_ptr};
        std::cout << "Use count: " << p0_ptr.use_count() << ", " << p2_ptr.use_count() << std::endl;

        p0_ptr.reset();
        std::cout << "RESET -> use count: " << p0_ptr.use_count() << ", " << p2_ptr.use_count() << std::endl;
        std::cout << "\n";

        std::shared_ptr<Test> p3_ptr = std::make_shared<Test>(3300);
        func(p3_ptr);
        std::cout << "Use count in main: " << p3_ptr.use_count() << std::endl;
    }
    return 0;
}
