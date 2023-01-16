

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern const & obj)
{
    *this = obj;
}

Intern & Intern::operator=(Intern const & obj)
{
    if (this == &obj)
        return *this;
    this->forms[0] = obj.forms[0];
    this->forms[1] = obj.forms[1];
    this->forms[2] = obj.forms[2];
    return *this;
}

Form    *Intern::makeForm(std::string formName, std::string target)
{
    this->forms[0] = new ShrubberyCreationForm(target);
    this->forms[1] = new RobotomyRequestForm(target);
    this->forms[2] = new PresidentialPardonForm(target);

    for (int i = 0; i < 3; i++)
    {
        if (this->forms[i]->getName() == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->forms[i]);
        }
    }
    throw FormDoesNotExist();
}