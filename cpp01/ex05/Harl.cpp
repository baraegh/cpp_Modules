
#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now\n";
}

void    Harl::complain(std::string level)
{
    void        (Harl::*fun[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string  str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int          i;

    for (i = 0; i < 4; i++)
    {
        if (str[i] == level)
        {
            (this->*fun[i])();
            break;
        }
    }
    if (i == 4)
        std::cout << "* complaint doesn't exist *\n";
}