#include "Animal.hpp"

Animal::Animal() : _type( "Animal" )
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( Animal &anim)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = anim;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=( const Animal &anim)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &anim)
	{
		this->_type = anim._type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}