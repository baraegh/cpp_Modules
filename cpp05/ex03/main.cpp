
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;

        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::string error_msg)
    {
        std::cerr << error_msg << std::endl;
    }
    // system("Leaks coffee_making");
    return 0;
}