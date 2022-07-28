
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream out_file {"new.txt", std::ios::app};

    if(!out_file)
    {
        std::cerr << "Problem to create\n";
        return 1;
    }

    std::string line;
    std::cout << "Enter line of the text:\n";
    std::getline(std::cin, line);

    out_file << line << std::endl;
   
   out_file.close();

    return 0;
}
