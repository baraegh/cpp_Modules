
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        ShrubberyCreationForm f("home");
        Bureaucrat b("bureaucrat", 11);

        b.signForm(f);
        f.execute(b);

    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::string error_msg)
    {
        std::cerr << error_msg << std::endl;
    }
    
    return 0;
}