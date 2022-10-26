
#include "Dog.hpp"

Dog::Dog()
    : Animal("Dog")
{
    std::cout << "[ Dog ]: default constructer called\n";
}

Dog::Dog(std::string type)
    : Animal(type)
{
    std::cout << "[ Dog ]: constructer called\n";
}

Dog::Dog(Dog const & obj)
{
    std::cout << "[ Dog ]: copy constructer called\n";
    *this = obj;
}

Dog::~Dog()
{
    std::cout << "[ Dog ]: destructer called\n";
}

void    Dog::makeSound() const
{
    std::cout << "Dog's sound: wooof\n";
}

Dog & Dog::operator=(Dog const & obj)
{
    std::cout << "[ Dog ]: copy assignement operator called\n";
    this->_type = obj._type;
    return *this;
}