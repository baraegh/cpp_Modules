

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
    private:
        unsigned int        _N;
        std::vector<int>    _v;

    public:
        Span();
        Span(unsigned int N);
        Span(Span const & obj);
        ~Span();

        Span &  operator=(Span const & obj);
        void    addNumber(int nbr);

        int     shortestSpan() const;
        int     longestSpan() const;

        void    addNumber(std::vector<int>::iterator it_begin
            , std::vector<int>::iterator it_end);

        class   ContainerIsFull : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Container is full";
                }
        };

        class   SpanCantBeFound : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Span can't be found";
                }
        };
};

#endif