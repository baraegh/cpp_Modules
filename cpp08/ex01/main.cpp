
#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::vector<int> v(10000);
        std::srand(time(NULL));
        std::generate(v.begin(), v.end(), std::rand);

        Span    p(v.size());
        p.addNumber(v.begin(), v.end());
        // p.addNumber(11);
        std::cout << p.shortestSpan() << std::endl;
        std::cout << p.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}