
#include "Convertor.hpp"

int main(int ac, char **av)
{
    if ( ac != 2)
    {
        std::cout << "Bad args number\nusage: ./conversion_of_scalar_types arg\n";
        return 1;
    }    
    Convertor convertor(av[1]);
    convertor.printValues();
    return 0;
}