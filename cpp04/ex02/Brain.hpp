
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
    private:
        std::string* _ideas;

    public:
        Brain();
        ~Brain();
        Brain(Brain const & obj);

        std::string* getIdeas() const;

        Brain & operator=(Brain const & obj);
};

#endif