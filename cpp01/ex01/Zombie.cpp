
#include "Zombie.hpp"

Zombie::Zombie ()
{
}

Zombie::Zombie (std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "destructor of " << this->name << " is called\n";
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::set_name(std::string name)
{
    this->name = name;
}

 std::string Zombie::get_name(void)
 {
    return this->name;
 }