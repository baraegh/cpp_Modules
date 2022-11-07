

#include "classes.hpp"

Base    *generate(void)
{
    srand((unsigned)time(NULL));
    int x = rand() % 2;
    if (x == 0)
        return new A;
    else if ( x == 1)
        return new B;
    return  new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "undefined type\n";
}

void identify(Base& p)
{
    try
    {
        A &a = reinterpret_cast<A&>(p);
        std::cout << "A\n";
        (void) a;
    }
    catch(const std::exception& e)
    {
        try
        {
            B &b = reinterpret_cast<B&>(p);
            std::cout << "B\n";
            (void) b;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &c = reinterpret_cast<C&>(p);
                std::cout << "C\n";
                (void) c;
            }
            catch(const std::exception& e)
            {
                (void) e;
                std::cerr << "undefined type\n";
            }
        }
    }
}