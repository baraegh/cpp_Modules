
# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form(), _target("")
{
    std::cout << "[ ShrubberyCreationForm ]: default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("shrubbery creation", 145, 137), _target(target)
{
    std::cout << "[ ShrubberyCreationForm ]: constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "[ ShrubberyCreationForm ]: destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & obj)
{
    std::cout << "[ ShrubberyCreationForm ]: copy constructor called\n";
    *this = obj;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & obj)
{
    std::cout << "[ ShrubberyCreationForm ]: copy assignment operator\n";
    if (this != &obj )
        this->_target = obj._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExeGrade())
        throw GradeTooLowException();
    else if (!this->getIsSigned())
        throw FormNotSigned();

    std::ofstream   ofs(this->_target + "_shrubbery");

    if (!ofs)
        throw "failed to create/open file" + this->_target + "_shrubbery";
    std::string tree = "                        ccee88oo\n \
                    C8O8O8Q8PoOb o8oo\n \
                    dOB69QO8PdUOpugoO9bD\n \
                    CgggbU8OU qOp qOdoUOdcb\n \
                        6OuU  /p u gcoUodpP\n \
                        \\\\//  /douUP\n \
                            \\\\////\n \
                            |||/|| \n\
                            |||\\/\n \
                            |||||\n \
                    .....//||||\\....";
    ofs << tree;
    ofs.close();
}