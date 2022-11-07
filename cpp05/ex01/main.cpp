
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form f("form", 1, 1);
        Bureaucrat b("bureaucrat", 11);
        b.signForm(f);
        f.beSigned(b);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}