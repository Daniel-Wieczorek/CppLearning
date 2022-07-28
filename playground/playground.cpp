//============================================================================
// Name        : Playground.cpp
// Author      : DWI
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>


class Car
{
    private:
    std::string carName;
    int registerNumber;

    public:
    // GETTERS
    std::string get_car_name(void) {return carName;}
    int get_register_number(void) {return registerNumber;}

    // SETTERS
    void set_car_name(std::string carName_arg) {carName = carName_arg;}
    void set_register_number(int registerNumber_arg) {registerNumber = registerNumber_arg;}

    // CONSTRUCTOR
    Car() // default constructor
    {
        carName ="";
        registerNumber =0;
    }

    // DESTRUCTOR
    ~Car();

};

class Calculator
{
public:
    using number_type = int; // this is a nested type alias
    std::vector<number_type> m_resultHistory{};

    number_type add(number_type a, number_type b)
    {
        auto result{ a+b };
        m_resultHistory.push_back(result);
        return result;
    }
};


/* TEMPLATES */
template <typename templateVar>
templateVar max (templateVar x, templateVar y)
{
    return ( x > y) ? x : y;
}

template <typename T, typename U>
auto min (T x, U y) // here we can use two different types as argument for a function. Auto keyword help to return correct type. 
{
    return (x > y) ? y : x;
}

// but in C++20 it is improved and we can use shorter version:
#ifdef CPP_20_SUPPORTED
auto ex (auto x, auto y)
{
    return (x > y) ? y : x;
}
#endif

int main()
{
    int var1 {100};
    int var2 {200};

    int array1 [5] = {0};
    int array2 [] = {1,2,3,4,5};

    for( auto i: array1)
    {
        std::cout << "Element value:  " << i << std::endl;
    }

    /* VECTORS */
    std::vector <int> myFirstVector {0, 100, 200, 300, 400};
    std::vector <char> myCharVector (3);

    myFirstVector.push_back(66);
    
    for (auto num: myFirstVector)
    {
        std::cout << "Vector Element: " << num << std::endl;
    }

    /* TEMPLATES */
    std::cout << " ***** TEMPLATES ***** "<< std::endl;
    std::cout << max<int>(100,200) << std::endl;
    std::cout << max(200,300) << std::endl; // template argument deduction

    char *string[20] = { "one", "two", "three"};
    printf("%c", string[1][1]);

    return 0;
}