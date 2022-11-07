

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : Form(), _target("")
{
    std::cout << "[ RobotomyRequestForm ]: default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("robotomy request", 72, 45) , _target(target)
{
    std::cout << "[ RobotomyRequestForm ]: constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "[ RobotomyRequestForm ]: destructor called\n";
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(RobotomyRequestForm const & obj)
{
     std::cout << "[ RobotomyRequestForm ]: copy assignment operator\n";
    if (this != &obj )
        this->_target = obj._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExeGrade())
        throw GradeTooLowException();
    else if (!this->getIsSigned())
        throw FormNotSigned();
    std::cout << this->_target << " has been robotomized successfully 50%% of the time\n";
}