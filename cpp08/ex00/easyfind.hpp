

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "iostream"

class   NoOccurrenceFound : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "No occurrence found";
        }
};

template <typename T>
void easyFind(T & con, const int & value)
{
    typename T::iterator it = std::find(con.begin(), con.end(), value);
    
    if (it != con.end())
    {
        std::cout << value << " founded in the container\n";
        return ;
    }
    throw NoOccurrenceFound();
}

#endif