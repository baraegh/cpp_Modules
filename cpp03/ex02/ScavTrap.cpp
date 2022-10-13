
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("", 0, 0, 0)
{
    std::cout << "ScavTrap: default constructor called\n";
}

ScavTrap::ScavTrap(std::string Name)
    : ClapTrap(Name, 100, 50, 20)
{
    std::cout << "ScavTrap: constructor called\n";
}

ScavTrap::ScavTrap(ScavTrap const & obj)
{
    std::cout << "ScavTrap: copy constructor called\n";
    *this = obj;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & obj)
{
    std::cout << "ScavTrap: copy assignement operator called\n";
    this->_Name = obj._Name;
    this->_HitPoint = obj._HitPoint;
    this->_EnergyPoint = obj._EnergyPoint;
    this->_AttackDamage = obj._AttackDamage;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getHitPoint() > 0 && this->getEnergyPoint() > 0)
    {
        std::cout << "ScavTrap: " << this->getName() << " attacks "
            << target << ", causing " << this->getAttackDamage() << " points of damage!\n";
        --this->_EnergyPoint;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " << this->getName() << " enter the gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: destructer called\n";
}