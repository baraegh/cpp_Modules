
#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(std::string type);
        Cat(Cat const & obj);
        ~Cat();

        void    makeSound() const;

        Cat & operator=(Cat const & obj);
};

# endif