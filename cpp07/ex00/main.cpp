
#include "whatever.hpp"
#include <iostream>

int main()
{

    int a = 1, b = 2;
    std::string str0 = "t00", str1 = "t01";
    
    std::cout << "before the swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "after the swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << "before the swap: str0 =\"" << str0
        << "\", str1 = \"" << str1 << "\"" << std::endl;
    ::swap(str0, str1);
    std::cout << "after the swap: str0 =\"" << str0
        << "\", str1 = \"" << str1 << "\"" << std::endl;
    std::cout << "min( str0, str1 ) = " << ::min(str0, str1) << std::endl;
    std::cout << "max( str0, str1 ) = " << ::max(str0, str1) << std::endl;

    return 0;
}