

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        RPN rpn = RPN(std::string(av[1]));

        rpn.process();
    }
    else
        std::cout << "Error: Invalid number of args\n";
    return 0;
}