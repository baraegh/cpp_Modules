

#include "RPN.hpp"

RPN::RPN(std::string exp)
    : _exp(exp)
{}

RPN::RPN(RPN const & rpn)
{
    *this = rpn;
}

RPN::~RPN(){}

RPN & RPN::operator=(RPN const & rpn)
{
    _exp = rpn._exp;
    _stack = rpn._stack;
    return *this;
}

RPN::RPN(){}

void    RPN::process()
{
    std::istringstream  iss(_exp);
    std::string         token;
    int                 nbr1, nbr2;

    while (iss >> token)
    {
        // if (token.size() > 1)
        // {
        //     std::cout << "Error: invalid value: " << token << "\n";
        //     return ;
        // }

        if (isdigit(token[0]))
        {
            if (token.size() > 1)
            {
                std::string nbr;

                for (size_t i = 0; i < token.size(); i++)
                {
                    if (!isdigit(token[i]))
                    {
                        std::cout << "Error: invalid value: " << token[i] << "\n";
                        return ;
                    }
                    nbr = token[i];
                    _stack.push(atoi(nbr.c_str()));
                    nbr.clear();
                }
            }
            else
                _stack.push(atoi(token.c_str()));
        }
        else if (_stack.size() > 1)
        {
            nbr2 = _stack.top();
            _stack.pop();
            nbr1 = _stack.top();
            _stack.pop();

            switch (token[0])
            {
                case '+':
                    _stack.push(nbr1 + nbr2);
                    break;
                case '-':
                    _stack.push(nbr1 - nbr2);
                    break;
                case '*':
                    _stack.push(nbr1 * nbr2);
                    break;
                case '/':
                    if (nbr2 == 0) {
                        std::cout << "Error: division by zero" << '\n';
                        return;
                    }
                    _stack.push(nbr1 / nbr2);
                    break;
                
                default:
                {
                    std::cout << "Error: invalid input: " << token << '\n';
                    return;
                }
            }
        }
        else
        {
            std::cout << "Error: invalid expression: " << _exp << '\n';
            return ;
        }
    }
    if (_stack.size() != 1)
    {
        std::cout << "Error: invalid expression: " << _exp << '\n';
        return ;
    }
    std::cout << _stack.top() << '\n';
}