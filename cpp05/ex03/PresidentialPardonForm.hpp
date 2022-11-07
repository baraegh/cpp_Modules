

#ifndef PRESIDENTREQUEST_HPP
# define PRESIDENTREQUEST_HPP

# include "Form.hpp"
# include <fstream>

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const & obj);

        PresidentialPardonForm & operator=(PresidentialPardonForm const & obj);

        void execute(Bureaucrat const & executor) const;
};
#endif