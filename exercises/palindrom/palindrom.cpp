#include <iostream>
#include <string>
#include <algorithm>

std::string checkPalindromeSimple(std::string &str)
{
    const std::string copy = str;
    std::reverse(str.begin(), str.end());

    return (copy == str) ? "Yes" : "No"; 
}

std::string checkPalindromeNormal(std::string &str)
{
    int strlength = str.length();

    for(int i = 0; i<(strlength/2); ++i)
    {
        if(str.at(i) != str.at(strlength-1-i))
            return "no";
    }
    return "yes";
}

int main()
{
    std::string test1 = "dupa";
    std::string test2 = "kajak";
    std::cout << checkPalindromeSimple(test1) <<std::endl;
    std::cout << checkPalindromeSimple(test2) <<std::endl;

    std::cout << checkPalindromeNormal(test1) <<std::endl;
    std::cout << checkPalindromeNormal(test2) <<std::endl;

    return 0;
}