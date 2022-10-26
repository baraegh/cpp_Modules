
#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat")
{
    std::cout << "[ Cat ]: default constructer called\n";
}

Cat::Cat(std::string type)
    : Animal(type)
{
    std::cout << "[ Cat ]: constructer called\n";
}

Cat::Cat(Cat const & obj)
{
    std::cout << "[ Cat ]: copy constructer called\n";
    *this = obj;
}

Cat::~Cat()
{
    std::cout << "[ Cat ]: destructer called\n";
}

void    Cat::makeSound() const
{
    std::cout << "Cat's sound: meow\n";
}

Cat & Cat::operator=(Cat const & obj)
{
    std::cout << "[ Cat ]: copy assignement operator called\n";
    this->_type = obj._type;
    return *this;
}