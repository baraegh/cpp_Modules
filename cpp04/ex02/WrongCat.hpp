

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(std::string type);
        WrongCat(WrongCat const & obj);
        ~WrongCat();

        void    makeSound() const;

        WrongCat & operator=(WrongCat const & obj);
};

# endif