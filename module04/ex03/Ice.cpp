#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice( Ice const & ic) : AMateria("ice")
{
	*this = ic;
}

Ice::~Ice()
{
}
Ice &Ice::operator=( const Ice &ic )
{
	if (this != &ic)
	{
		this->_type = ic._type;
	}
	return *this;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}