

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("presidential pardon", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("presidential pardon", 25, 5) , _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & obj)
    : Form(obj)
{
    *this = obj;
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