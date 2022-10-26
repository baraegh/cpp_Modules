
#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain*  _brains;

    public :
        Dog();
        Dog(std::string type);
        Dog(Dog const & obj);
        ~Dog();

        void    makeSound() const;

        Dog & operator=(Dog const & obj);
};

#endif