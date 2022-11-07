

#include "classes.hpp"

int main()
{
    Base *b1, *b2;

    b1 = generate();
    b2 = generate();
    identify(b1);
    identify(b2);
    identify(*b1);
    identify(*b2);
    return 0;
}