

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    if (ac == 2)
    {
        PmergeMe p(av[1]);
        if (p.setup())
            p.sort();
    }
    else
        std::cout << "Error: invalid number of args\n";
    return 0;
}