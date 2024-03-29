

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : Form("robotomy request", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("robotomy request", 72, 45) , _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & obj)
    :Form(obj)
{
    *this = obj;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & obj)
{
    if (this == &obj)
        return *this;
    this->_target = obj._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExeGrade())
        throw GradeTooLowException();
    else if (!this->getIsSigned())
        throw FormNotSigned();
    std::cout << this->_target << " has been robotomized successfully 50% of the time\n";
}