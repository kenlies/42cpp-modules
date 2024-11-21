#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << "----------Brain test----------" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}
	/*
	const Animal* a[4];
	a[0] = new Dog();
	a[1] = new Dog();
	a[2] = new Cat();
	a[3] = new Cat();
	delete a[0];
	delete a[1];
	delete a[2];
	delete a[3];
	*/
	std::cout << "----------End Destructors----------" << std::endl;

	return 0;
}
