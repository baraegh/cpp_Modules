

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>


class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const & obj);
        ~Bureaucrat();

        std::string const   getName() const;
        int                 getGrade() const;
        void                increment();
        void                decrement();

        Bureaucrat & operator=(Bureaucrat const & obj);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade too low";
                }
        };
};

std::ostream    & operator<<(std::ostream &o, Bureaucrat const & obj);

#endif