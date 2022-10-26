
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
    return 0;
}
