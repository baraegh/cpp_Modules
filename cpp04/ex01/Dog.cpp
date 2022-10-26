
#include "Dog.hpp"

Dog::Dog()
    : Animal("Dog"), _brains(new Brain())
{
    std::cout << "[ Dog ]: default constructer called\n";
}

Dog::Dog(std::string type)
    : Animal(type), _brains(new Brain())
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
    delete this->_brains;
}

void    Dog::makeSound() const
{
    std::cout << "Dog's sound: wooof\n";
}

Dog & Dog::operator=(Dog const & obj)
{
    std::cout << "[ Dog ]: copy assignement operator called\n";
    this->_type = obj._type;
    if (obj._brains)
    {
        delete this->_brains;
        this->_brains = new Brain();
        for (int i = 0; i < 100; i++)
            this->_brains->getIdeas()[i] = obj._brains->getIdeas()[i];
    }
    else
        this->_brains = NULL;
    return *this;
}