
#include <iostream>

int main(int ac, char **av)
{
    if ( ac != 2)
    {
        std::cout << "usage: ./conversion_of_scalar_types arg\n";
        return 1;
    }

    std::string arg(av[1]);
    

    return 0;
}