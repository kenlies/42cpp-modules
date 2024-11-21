#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain( Brain &brn)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brn;
}

Brain &Brain::operator=( const Brain &brn)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &brn)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = brn._ideas[i];
	return *this;
}