
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form f00("form", 1, 1);
        Bureaucrat b00("bureaucrat", 1);
        b00.signForm(f00);
        f00.beSigned(b00);

        Form f01("form", 3, 2);
        Bureaucrat b01("bureaucrat", 5);
        b01.signForm(f01);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}