#include <iostream>
#include <string>

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw 0;
    if (miles < 0 || gallons < 0)
        throw std::string{"Negative value error"};
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
    catch (int &exception)
    {
        std::cerr << "Error occured: " << exception << std::endl;
    }
    catch (std::string &string_ex)
    {
        std::cerr << "String error\n";
    }

    return 0;
}