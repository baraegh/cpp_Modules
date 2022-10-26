
#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat"), _brains(new Brain())
{
    std::cout << "[ Cat ]: default constructer called\n";
}

Cat::Cat(std::string type)
    : Animal(type), _brains(new Brain())
{
    std::cout << "[ Cat ]: constructer called\n";
}

Cat::Cat(Cat const & obj) : _brains(new Brain())
{
    std::cout << "[ Cat ]: copy constructer called\n";
    *this = obj;
}

Cat::~Cat()
{
    std::cout << "[ Cat ]: destructer called\n";
    delete this->_brains;
}

void    Cat::makeSound() const
{
    std::cout << "Cat's sound: meow\n";
}

Cat & Cat::operator=(Cat const & obj)
{
    std::cout << "[ Cat ]: copy assignement operator called\n";
    this->_type = obj._type;
    delete this->_brains;
    if (obj._brains)
    {
        this->_brains = new Brain();
        for (int i = 0; i < 100; i++)
            this->_brains->getIdeas()[i] = obj._brains->getIdeas()[i];
    }
    else
        this->_brains = NULL;
    return *this;
}