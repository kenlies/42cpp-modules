#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	std::cout << "------------------------------" << std::endl;

	const WrongAnimal* cat1 = new WrongCat();
	const WrongCat* cat2 = new WrongCat();
	
	cat1->makeSound();
	cat2->makeSound();

	delete cat1;
	delete cat2;

	return 0;
}