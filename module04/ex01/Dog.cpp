#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	try
	{
		this->_brain = new Brain();
	}
	catch (std::bad_alloc)
	{
		std::cout << "Dog Brain allocation fail" << std::endl;
	}
}

Dog::Dog( const Dog &dg )
{
	*this = dg;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=( const Dog &dg )
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &dg)
	{
		this->_type = dg._type;
		try
		{
			this->_brain = new Brain();
		}
		catch (std::bad_alloc)
		{
			std::cout << "Dog Brain allocation fail" << std::endl;
		}
		//this->_brain = dg._brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Wuh" << std::endl;
}
