
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        
        MutantStack(){}
        ~MutantStack(){}

        MutantStack(MutantStack const & obj) { *this = obj; }

        MutantStack & operator=(MutantStack const & obj)
        {
            std::stack<T>::operator=(obj);
            return *this;
        }

        iterator    begin(){ return this->c.begin();}
        iterator    end(){ return this->c.end();}

        const_iterator    begin() const { return this->c.begin();}
        const_iterator    end() const { return this->c.end();}
};



#endif