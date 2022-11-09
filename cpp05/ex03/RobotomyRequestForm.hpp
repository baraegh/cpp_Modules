

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & obj);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
        RobotomyRequestForm & operator=(RobotomyRequestForm const & obj);
};

#endif