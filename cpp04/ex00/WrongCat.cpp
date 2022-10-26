
#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    std::cout << "[ WrongCat ]: default constructer called\n";
}

WrongCat::WrongCat(std::string type)
    : WrongAnimal(type)
{
    std::cout << "[ WrongCat ]: constructer called\n";
}

WrongCat::WrongCat(WrongCat const & obj)
{
    std::cout << "[ WrongCat ]: copy constructer called\n";
    *this = obj;
}

WrongCat::~WrongCat()
{
    std::cout << "[ WrongCat ]: destructer called\n";
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat's sound: meow\n";
}

WrongCat & WrongCat::operator=(WrongCat const & obj)
{
    std::cout << "[ WrongCat ]: copy assignement operator called\n";
    this->_type = obj._type;
    return *this;
}