
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap b("barae");
    ClapTrap a("someone");

    b.attack("someone");
    b.PrintInfo();
    
    a.takeDamage(1);
    a.PrintInfo();
    
    a.beRepaired(1);
    a.PrintInfo();
    return 0;
}