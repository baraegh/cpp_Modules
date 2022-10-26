
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

    const Animal* meta = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    const WrongAnimal* w_animal = new WrongAnimal();
    const WrongAnimal* w_cat = new WrongCat();
    
    std::cout << d->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;

    std::cout << w_animal->getType() << " " << std::endl;
    std::cout << w_cat->getType() << " " << std::endl;

    c->makeSound();
    d->makeSound();
    meta->makeSound();

    w_cat->makeSound();
    w_animal->makeSound();

    delete meta;
    delete d;
    delete c;
    delete w_animal;
    delete w_cat;
    return 0;
}