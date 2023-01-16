
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("t00", 2);

        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
       
        Bureaucrat c;
        c = b;
        std::cout << c.getName() << std::endl;
        std::cout << c.getGrade() << std::endl;

        Bureaucrat d("t00", -1);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}