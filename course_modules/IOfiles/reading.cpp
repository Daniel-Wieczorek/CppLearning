
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file;
    in_file.open("text.txt");

    std::string line;
    char c{};

    if (!in_file.is_open())
    {
        std::cerr << "Problem with open/n";
        return 1;
    }
    /*
    while (!in_file.eof())
    {
        in_file >> line;
        std::cout << line << std::endl;
    }
    */

   /*
    // FORMATED WAY:
   while (std::getline(in_file, line))
   {
       std::cout << line << std::endl;
   }
    */

    // UNFORMATTED WAY:
    std::cout << "==== UNFORMATTED ====\n";

    while (in_file.get(c))
    {
        std::cout << c << " ";
    }
    

   
   in_file.close();

    return 0;
}
