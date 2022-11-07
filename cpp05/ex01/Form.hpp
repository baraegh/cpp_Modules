

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _grade;
        int const           _exeGrade;


    public:
        Form();
        Form(std::string    name, int   grade, int  exeGrade);
        ~Form();
        Form(Form const & obj);

        Form &      operator=(Form const & obj);
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGrade() const;
        int         getExeGrade() const;
        void        beSigned(Bureaucrat obj);

        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return "Grade too high";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public :
                const char * what() const throw()
                {
                    return "Grade too low";
                }
        };
};

std::ostream    & operator<<(std::ostream &o, Form const & obj);

#endif