
#include "Brain.hpp"

Brain::Brain()
    : _ideas(new std::string[100])
{
    std::cout << "[ Brain ]: default constructer called\n";
}

Brain::~Brain()
{
    std::cout << "[ Brain ]: destructer called\n";
    delete [] _ideas;
}

Brain::Brain(Brain const & obj)
{
    std::cout << "[ Brain ]: copy constructer called\n";
    *this = obj;
}

std::string* Brain::getIdeas() const
{
    return this->_ideas;
}

Brain & Brain::operator=(Brain const & obj)
{
    std::cout << "[ Brain ]: copy assignement operator called\n";
    for (int i = 0; i < 100; i++)
            this->_ideas[i] = obj._ideas[i];
    return *this;
}