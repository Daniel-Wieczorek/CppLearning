#include <iostream>
#include <string>
#include <algorithm>

bool isParenthesisCorrect(const std::string input)
{
    const std::string parenthesisAllowed = "(){}";
    int semicolonOpen{ 0 };
    int semicolonClose{ 0 };

    for (const auto& symbol:input)
    {
        if (parenthesisAllowed.find(symbol)==std::string::npos)
            continue;
        else
        {
            if (symbol==parenthesisAllowed.at(0) ||
                symbol==parenthesisAllowed.at(2))
                ++semicolonOpen;
            if (symbol==parenthesisAllowed.at(1) ||
                symbol==parenthesisAllowed.at(3))
                ++semicolonClose;
        }
    }
    return (semicolonOpen==semicolonClose) ? true : false;
}

int main()
{
    std::string test1 = "(a+b)+c";
    std::string test2 = "(a+b)+(c+d+df*fww-c";
    std::string test3 = "(a+b)+c+d+{}";

    std::cout << isParenthesisCorrect(test1) << std::endl;
    std::cout << isParenthesisCorrect(test2) << std::endl;
    std::cout << isParenthesisCorrect(test3) << std::endl;

    return 0;
}