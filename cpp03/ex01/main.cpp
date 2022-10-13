
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap b("barae");
    ScavTrap a("someone");

    b.attack("enemy");
    b.PrintInfo();
    
    a.takeDamage(2);
    a.PrintInfo();
    
    a.beRepaired(2);
    a.PrintInfo();

    a.guardGate();

    return 0;
}