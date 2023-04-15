
# include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        if (access(av[1], F_OK | R_OK) == 0)
        {
            BitcoinExchange b = BitcoinExchange(std::string(av[1]));
            if (b.setup())
                b.evaluate();
            else
                std::cerr << "Error: invalid database\n";
        }
        else
            std::cerr << "Error: input file not exist/readable\n";
    }
    else
        std::cerr << "Error: invalid number of args\n";
    return 0;
}