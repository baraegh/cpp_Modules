
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name(""), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw  GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & obj)
    : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat(){}

std::string const   Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void    Bureaucrat::increment()
{
    if (this->_grade == 1)
        throw GradeTooHighException();
    --this->_grade;
}

void    Bureaucrat::decrement()
{
    if (this->_grade == 150)
        throw GradeTooLowException();
    ++this->_grade;
}

Bureaucrat  & Bureaucrat::operator=(Bureaucrat const & obj)
{
    if (this != &obj )
        this->_grade = obj._grade;
    return *this;
}

std::ostream    & operator<<(std::ostream &o, Bureaucrat const & obj)
{
    o << "[ Bureaucrat ]: "<< obj.getName() << ",  bureaucrat grade " << obj.getGrade() << ".\n";
    return o;
}

void    Bureaucrat::signForm(Form & obj) const
{
    try
    {
        obj.beSigned(*this);
        std::cout << this->_name << " signed " << obj.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn’t sign " << obj.getName()
            << " because: " << e.what() << '\n';
    }
}
