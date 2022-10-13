

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string Name);
        FragTrap(FragTrap const & obj);
        ~FragTrap();

        void    attack(const std::string& target);
        void    highFivesGuys(void);

        FragTrap &operator=(FragTrap const & obj);
};

# endif