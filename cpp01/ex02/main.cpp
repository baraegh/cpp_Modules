
#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "The memory address of str: " << &str << std::endl;
    std::cout << "The memory address held by strPTR: " << strPTR << std::endl;
    std::cout << "The memory address held by strREF: " << &strREF << std::endl;
    std::cout << "---------------------------------------\n";
    std::cout << "The value of the str: " << str << std::endl;
    std::cout << "The value pointed to by strPTR: " << *strPTR << std::endl;
    std::cout << "The value pointed to by strREF: " << strREF << std::endl;
    return 0;
}