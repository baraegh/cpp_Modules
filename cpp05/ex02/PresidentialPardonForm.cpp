

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form(), _target("")
{
    std::cout << "[ PresidentialPardonForm ]: default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("presidential pardon", 72, 45) , _target(target)
{
    std::cout << "[ PresidentialPardonForm ]: constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[ PresidentialPardonForm ]: destructor called\n";
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & obj)
{
    if (this == &obj)
        return *this;
    this->_target = obj._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExeGrade())
        throw GradeTooLowException();
    else if (!this->getIsSigned())
        throw FormNotSigned();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}