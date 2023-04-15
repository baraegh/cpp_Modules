

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>

class RPN
{
    private:
        std::string     _exp;
        std::stack<int> _stack;

    public:
        RPN(std::string exp);
        RPN(RPN const & rpn);
        ~RPN();

        RPN &   operator=(RPN const & rpn);
        void    process();
    
    private:
        RPN();

};


#endif