
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animals[6] = {new Cat() , new Cat(), new Cat(),
                                new Dog(), new Dog(), new Dog()};

    for (int i = 0; i < 6; i++)
        delete animals[i];
    // system("Leaks I_dont_want_to_set_the_the_world_on_fire");
    return 0;
}
