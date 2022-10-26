
#include "Animal.hpp"

Animal::Animal()
    : _type("Animal")
{
    std::cout << "[ Animal ]: default constructer called\n";
}

Animal::Animal(std::string type)
    : _type(type)
{
    std::cout << "[ Animal ]: constructer called\n";
}

Animal::Animal(Animal const & obj)
{
    std::cout << "[ Animal ]: copy constructer called\n";
    *this = obj;
}

Animal::~Animal()
{
    std::cout << "[ Animal ]: destructer called\n";
}

void    Animal::makeSound() const
{
    std::cout << "Animal's sound: ???\n";
}

std::string Animal::getType() const
{
    return this->_type;
}

Animal & Animal::operator=(Animal const & obj)
{
    std::cout << "[ Animal ]: copy assignement operator called\n";
    this->_type = obj._type;
    return *this;
}