#include <iostream>
#include <string>
#include <algorithm>

std::string reverse(std::string inputString)
{ 
    std::string outputString{ "" };

    for (int i = inputString.length()-1; i>=0;--i)
        outputString.push_back(inputString.at(i));

    return outputString;
}

std::string take_word()
{
    return "Hello World";
}

int main()
{
    std::string test = "a2b345";
    std::cout << reverse(test) << std::endl;
    std::cout << reverse(std::string("abcd")) << std::endl;
    std::cout << reverse(take_word()) << std::endl;

    return 0;
}
