
#include "FragTrap.hpp"

FragTrap::FragTrap()
    :ClapTrap("", 0, 0, 0)
{
    std::cout << "FragTrap: default constructer called\n";
}

FragTrap::FragTrap(std::string Name)
    :ClapTrap(Name, 100, 30, 30)
{
    std::cout << "FragTrap: constructer called\n";
}

FragTrap::FragTrap(FragTrap const & obj)
{
    std::cout << "FragTrap: copy constructer called\n";
    *this = obj;
}

FragTrap & FragTrap::operator=(FragTrap const & obj)
{
    std::cout << "FragTrap: copy assignement operator called\n";
    this->_Name = obj._Name;
    this->_HitPoint = obj._HitPoint;
    this->_EnergyPoint = obj._EnergyPoint;
    this->_AttackDamage = obj._AttackDamage;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (this->getHitPoint() > 0 && this->getEnergyPoint() > 0)
    {
        std::cout << "FragTrap: " << this->getName() << " attacks "
            << target << ", causing " << this->getAttackDamage() << " points of damage!\n";
        --this->_EnergyPoint;
    }
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << this->getName() << " highFivesGuys\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: destructer called\n";
}