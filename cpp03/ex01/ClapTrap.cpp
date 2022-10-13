
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _Name(""), _HitPoint(0), _EnergyPoint(0), _AttackDamage(0)
{
    std::cout << "ClapTrap: default constructer called\n";
}

ClapTrap::ClapTrap(std::string Name, unsigned int HitPoint, 
    unsigned int EnergyPoint, unsigned int AttackDamage)
    : _Name(Name), _HitPoint(HitPoint), _EnergyPoint(EnergyPoint),
    _AttackDamage(AttackDamage)
{
    std::cout << "ClapTrap: constructer called\n";
}

ClapTrap::ClapTrap(ClapTrap const & obj)
{
    std::cout << "ClapTrap: copy constructer called\n";
    *this = obj;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: destructer called\n";
}

ClapTrap & ClapTrap::operator=(ClapTrap const & obj)
{
    std::cout << "ClapTrap: copy assignement operator called\n";
    this->_Name = obj._Name;
    this->_HitPoint = obj._HitPoint;
    this->_EnergyPoint = obj._EnergyPoint;
    this->_AttackDamage = obj._AttackDamage;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_HitPoint > 0 && this->_EnergyPoint > 0)
    {
        std::cout << "ClapTrap: " << this->_Name << " attacks "
            << target << ", causing " << this->_AttackDamage << " points of damage!\n";
        --this->_EnergyPoint;
        return ;
    }
    std::cout << "ClapTrap: " << this->_Name << " has no energy !\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_HitPoint >= amount)
    {
        std::cout << this->_Name << " take " << amount << " damage points\n";
        this->_HitPoint -= amount;
        return ;
    }
    std::cout << "ClapTrap: " << this->_Name << " is died !\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_EnergyPoint > 0 && this->_HitPoint > 0)
    {
        std::cout << this->_Name << " repairs itself by "
            << amount << " points\n";
        this->_HitPoint += amount;
        --this->_EnergyPoint;
        return ;
    }
    std::cout << "ClapTrap: " << this->_Name << " has no energy !\n";
}

std::string ClapTrap::getName(void) const
{
    return this->_Name;
}

int ClapTrap::getHitPoint(void) const
{
    return this->_HitPoint;
}

int ClapTrap::getEnergyPoint(void) const
{
    return this->_EnergyPoint;
}

int ClapTrap::getAttackDamage(void) const
{
    return this->_AttackDamage;
}

void    ClapTrap::PrintInfo()
{
    std::cout << this->getName() << " has " << this->getHitPoint() << " hit point and "
        << this->getEnergyPoint() << " energy points\n";
}