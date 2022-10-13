

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    private:
        std::string     _Name;
        unsigned int    _HitPoint;
        unsigned int    _EnergyPoint;
        unsigned int    _AttackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string Name);
        ClapTrap(ClapTrap const & obj);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void) const;
        int         getHitPoint(void) const;
        int         getEnergyPoint(void) const;
        int         getAttackDamage(void) const;

        ClapTrap & operator=(ClapTrap const & obj);

        void        PrintInfo();
};


#endif