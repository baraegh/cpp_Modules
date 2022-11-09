

#include "iter.hpp"
#include <string>

int main()
{
    std::string str("hello world!");
    ::iter(str.c_str(), str.length(), printValue);

    std::cout << std::endl; 

    int arr[4] = {1, 2, 3, 4};
    ::iter<int>(arr, 4, printValue);

    return 0;
}