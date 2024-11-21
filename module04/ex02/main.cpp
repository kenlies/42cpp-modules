#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	//AAnimal test;

	delete j;//should not create a leak
	delete i;

	Dog basic;
	{
		Dog tmp = basic;
	}
	
	const AAnimal* a[4];
	a[0] = new Dog();
	a[1] = new Dog();
	a[2] = new Cat();
	a[3] = new Cat();
	delete a[0];
	delete a[1];
	delete a[2];
	delete a[3];

	return 0;
}
