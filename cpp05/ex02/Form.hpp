

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
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

        Form &              operator=(Form const & obj);
        std::string         getName() const;
        bool                getIsSigned() const;
        int                 getGrade() const;
        int                 getExeGrade() const;
        virtual void        beSigned(Bureaucrat obj);
        virtual void        execute(Bureaucrat const & executor) const = 0;

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

        class FormNotSigned : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return "Form not signed yet";
                }
        };
};

std::ostream    & operator<<(std::ostream &o, Form const & obj);

#endif