

#include "Serialization.hpp"

int main()
{
    uintptr_t a;
    Data    *data = new Data();

    data->nbr = 5;
    std:: cout << data << std::endl;

    a = serialize(data);
    std:: cout << a << std::endl;

    data = deserialize(a);
    std:: cout << data << std::endl;
    std:: cout << data->nbr << std::endl;

    return 0;
}