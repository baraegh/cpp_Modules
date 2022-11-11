
#include "Span.hpp"

Span::Span()
    : _N(0){}

Span::Span(unsigned int N)
    : _N(N){}

Span::Span(Span const & obj)
{
    *this = obj;
}

Span::~Span(){}

Span &  Span::operator=(Span const & obj)
{
    this->_N = obj._N;
    this->_v = obj._v;
    return *this;
}

void    Span::addNumber(int nbr)
{
    if (this->_v.size() == this->_N)
        throw ContainerIsFull();
    this->_v.push_back(nbr);
}

int     Span::shortestSpan() const
{
    if (this->_v.empty() || this->_v.size() == 1)
        throw SpanCantBeFound();
    
    std::vector<int>    tmpV = this->_v;

    std::sort(tmpV.begin(), tmpV.end());
    
    int minSpan =  tmpV[1] - tmpV[0];
    for (long unsigned int i = 1; i < tmpV.size() - 1; i++)
    {
        if (minSpan > tmpV[i + 1] - tmpV[i])
            minSpan = tmpV[i + 1] - tmpV[i];
    }
    return minSpan;
}

int     Span::longestSpan() const
{
    if (this->_v.empty() || this->_v.size() == 1)
        throw SpanCantBeFound();
    
    std::vector<int>    tmpV = this->_v;

    std::sort(tmpV.begin(), tmpV.end(), std::greater<int>());
    return tmpV[0] - tmpV[tmpV.size() - 1];
}

void    Span::addNumber(std::vector<int>::iterator it_begin
            , std::vector<int>::iterator it_end)
{
    if (this->_v.size() == this->_N)
        throw ContainerIsFull();
    this->_v.insert(this->_v.end(), it_begin, it_end);
}