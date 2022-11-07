
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name(""), _grade(150)
{
    std::cout << "[ Bureaucrat ]: default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw  GradeTooLowException();
    std::cout << "[ Bureaucrat ]: constructor called\n";
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & obj)
    : _name(obj._name), _grade(obj._grade)
{
    std::cout << "[ Bureaucrat ]: copy constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[ Bureaucrat ]: destructor called\n";
}

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
    std::cout << "[ Bureaucrat ]: copy assignement operator\n";
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

void    Bureaucrat::executeForm(Form const & form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}