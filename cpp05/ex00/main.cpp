
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("t", 2);

        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
       
        Bureaucrat c;
        c = b;
        std::cout << c.getName() << std::endl;
        std::cout << c.getGrade() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}