
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    :name(name){}

HumanB::~HumanB()
{
}

void    HumanB::attack(void)
{
    if (weapon)
        std::cout << this->name << " attacks with their "
            << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}