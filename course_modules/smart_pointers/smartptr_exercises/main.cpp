#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*
    weak_ptr<DataType> ptrName;

    Lets assume situation that class A is pointing to B and class B is pointing to A (using shared_ptr)
    So class A keeps alive class B and class B keeps alive class A. In such situation once one of the
    object is destroyed for B class (on the stack) but data on the heap wont be destroyed (memory leak) 

    Solution for that would be to make on of the pointers weak. To do that we have to know what class ownes
    what (which one is parent and which one is child).

*/

class Test
{
    private:
    int data;

    public:
    Test() : Test{0}
    {
        //std::cout << "Default constructor called" << std::endl;
    }
    
    Test(int inData): data{inData}
    {
        //std::cout << "One arg contructor called" << std::endl;
    }

    ~Test ()
    {
        //std::cout << "Destructor called " << std::endl; 
    }

    int get_data() {return data;} // getter
    void set_data(int inData) { data = inData;} // setter

};

int main()
{
    // Test obj1 = new Test{1000};
    // delete obj1;

    // unique pointer
    std::unique_ptr<Test> ptr_t1 {new Test{100}};
    //or using make_unique what is better!
    std::unique_ptr<Test> ptr_t2 = std::make_unique<Test>(1000);

    std::unique_ptr<Test> t3;
    t3 = std::move(ptr_t1);

    std::shared_ptr<int> p1 = std::make_shared<int>(100);
    std::shared_ptr<int> p2 { p1 };
    std::shared_ptr<int> p3;
    p3 = p1;

    std::cout << "Value of the shared_ptr: " << p1.unique() << std::endl;
    std::cout << "Address of the shared_ptr: " << *p1 << std::endl;

    std::shared_ptr<Test> test1 = std::make_shared<Test>(100);
    std::shared_ptr<Test> test2 = std::make_shared<Test>(200);
    std::shared_ptr<Test> test3 = std::make_shared<Test>(300);

    std::cout << "Use count before vector init: " << test1.get() << std::endl;
    

    std::vector<std::shared_ptr<Test>> testVector;
    testVector.push_back(test1);
    testVector.push_back(test2);
    testVector.push_back(test3);

    for(const auto &var : testVector)
    {
        std::cout << "Use count after vector init: " << var.use_count() << std::endl;
    }

}

