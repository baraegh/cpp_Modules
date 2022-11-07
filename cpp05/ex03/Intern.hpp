

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        Form *forms[3];

    public:
        Intern();
        ~Intern();
        Intern(Intern const & obj);

        Intern &operator=(Intern const & obj);

        Form    *makeForm(std::string formName, std::string target);

        class FormDoesNotExist : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return "form doesn't exist";
                }
        };
};

#endif