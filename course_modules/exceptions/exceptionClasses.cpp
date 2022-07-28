#include <iostream>
#include <string>

class DivideByZeroException
{

};

class NegativeValueException
{

};

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw DivideByZeroException();
    if (miles < 0 || gallons < 0)
        throw NegativeValueException();
    return static_cast<double>(miles) / gallons;
}

int main()
{

    int miles{}, gallons{};
    double miles_per_galon{}, result {};
    miles = -31;
    gallons = 5;

    try
    {
        result = calculate_mpg(miles,gallons);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const DivideByZeroException &exception)
    {
        std::cerr << "Error occured: " << std::endl;
    }
    catch (const NegativeValueException &exception)
    {
        std::cerr << "String error\n";
    }

    return 0;
}