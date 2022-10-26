
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : _type("WrongAnimal")
{
    std::cout << "[ WrongAnimal ]: default constructer called\n";
}

WrongAnimal::WrongAnimal(std::string type)
    : _type(type)
{
    std::cout << "[ WrongAnimal ]: constructer called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const & obj)
{
    std::cout << "[ WrongAnimal ]: copy constructer called\n";
    *this = obj;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[ WrongAnimal ]: destructer called\n";
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal's sound: ???\n";
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & obj)
{
    std::cout << "[ WrongAnimal ]: copy assignement operator called\n";
    this->_type = obj._type;
    return *this;
}