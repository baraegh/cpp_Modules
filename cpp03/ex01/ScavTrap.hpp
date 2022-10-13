

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

    public :
        ScavTrap();
        ScavTrap(std:: string Name);
        ScavTrap(ScavTrap const & obj);
        ~ScavTrap();

        ScavTrap &operator=(ScavTrap const & obj);

        void    attack(const std::string& target);
        void    guardGate();
        void    PrintInfo();
};

#endif