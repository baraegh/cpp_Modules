
#include "Zombie.hpp"

int main(void)
{
    Zombie *z = zombieHorde(5, "foo");
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << " ";
        z[i].announce();
    }
    delete[] z;
    return 0;
}