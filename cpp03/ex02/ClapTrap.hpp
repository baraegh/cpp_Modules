

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    protected:
        std::string     _Name;
        unsigned int    _HitPoint;
        unsigned int    _EnergyPoint;
        unsigned int    _AttackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string Name, unsigned int HitPoint,
            unsigned int EnergyPoint, unsigned int AttackDamage);
        ClapTrap(ClapTrap const & obj);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void) const;
        int         getHitPoint(void) const;
        int         getEnergyPoint(void) const;
        int         getAttackDamage(void) const;

        void    PrintInfo();

        ClapTrap & operator=(ClapTrap const & obj);
};


#endif