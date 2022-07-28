#include <iostream>
#include <string>
#include <vector>


void display(const std::vector<std::string> *const my_vector)
{
    for(auto str: *my_vector)
        std::cout << str << " ";
    std::cout << std::endl;

    // my_vector = nullptr -> disallowed because my_vector is a constant
}

int *create_array(size_t size, int init_value=0)
{
    int *new_storage {nullptr};
    new_storage = new int[size];

    for(size_t i{0}; i < size; i++)
    {
        *(new_storage+i) = init_value;
    }

    return new_storage;
}

void display(const int *const array, size_t size)
{
    for(size_t i{0}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> stooges {"Larry", "Moe", "Curly"};
    display(&stooges);

    int *my_array {nullptr};
    size_t size {};
    int init_value {};

    //std::cin >> size >> init_value;

    //my_array = create_array(size, init_value);
    //display(my_array, size);

    delete [] my_array;

    std::vector<std::string> names {"Daniel", "Sraniel", "Matte"};

    for (auto &name : names)
    {
        name = "XXX";
        
    }
    
    for (auto const &result : names)
        std::cout << result << " ";
    std::cout << std::endl;

    return 0;
}