#include <iostream>
#include <string>
#include <algorithm>

void sortString(std::string &input)
{
    std::sort(input.begin(), input.end());
    std::cout << input << std::endl;
}

std::string sortStringValue(std::string input)
{
    int i{}, j{};
    std::string outputValue{ "" };

    for (i = 0; i<input.length()-1; i++)
    {
        for (j = 0; j<input.length()-i-1;j++)
        {
            if (input [ j ]>input [ j+1 ])
            {
                unsigned char temp = input [ j+1 ];
                input [ j+1 ] = input [ j ];
                input [ j ] = temp;
            }
        }
    }
    outputValue = input;
    return outputValue;
}

int main()
{
    std::string test1 = "aaawaaabfawfwbbccwafawfscc";
    std::string test2 = "aaawaaabfawfwbbccwafawfscc";

    sortString(test1);
    std::cout << sortStringValue(test2) << std::endl;
    

    return 0;
}