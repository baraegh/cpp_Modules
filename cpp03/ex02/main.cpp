
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ScavTrap b("barae");
    FragTrap a("someone");

    b.attack("enemy");
    b.PrintInfo();
    
    a.takeDamage(2);
    a.PrintInfo();
    
    a.beRepaired(2);
    a.PrintInfo();

    a.highFivesGuys();

    return 0;
}