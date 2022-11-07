
#include "Form.hpp"

Form::Form()
    : _name(""), _isSigned(false), _grade(150), _exeGrade(150)
{
    std::cout << "[ Form ]: default constructor called\n";
}

Form::Form(std::string    name, int   grade, int  exeGrade)
    : _name(name), _grade(grade), _exeGrade(exeGrade)
{
    if (grade < 1 || exeGrade < 1)
        throw GradeTooHighException();
    if (grade > 150 || exeGrade > 150)
        throw GradeTooLowException();
    std::cout << "[ Form ]: constructor called\n";
    this->_isSigned = false;
}

Form::~Form()
{
    std::cout << "[ Form ]: destructor called\n";
}

Form::Form(Form const & obj)
    : _name(obj._name), _isSigned(obj._isSigned), _grade(obj._grade),
    _exeGrade(obj._exeGrade)
{
    std::cout << "[ Form ]: copy constructor called\n";
}

Form &      Form::operator=(Form const & obj)
{
    std::cout << "[ Form ]: copy assignement operator\n";
    if (this != &obj )
        this->_isSigned = obj._isSigned;
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

bool    Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGrade() const
{
    return this->_grade;
}

int Form::getExeGrade() const
{
    return this->_exeGrade;
}

void        Form::beSigned(Bureaucrat obj)
{
    if (obj.getGrade() <= this->_grade)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream    & operator<<(std::ostream &o, Form const & obj)
{
    o << "[ Form ]: " << obj.getName();
    if (obj.getIsSigned())
        o << " that's already signed. ";
    else
        o << " that's not signed yet. ";
    o << "it require at least " << obj.getGrade() << " to be signed & "
        << obj.getExeGrade() << " to be executed\n";
    return o; 
}
