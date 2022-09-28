
#include "Zombie.hpp"

int main(void)
{
    int n = 5;
    Zombie *z = zombieHorde(n, "foo");

    for (int i = 0; i < n; i++)
    {
        std::cout << i << " ";
        z[i].announce();
    }
    delete[] z;
    return 0;
}