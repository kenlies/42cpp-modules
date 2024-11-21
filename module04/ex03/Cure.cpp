#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure( Cure const & cur) : AMateria("cure")
{
	*this = cur;
}

Cure::~Cure()
{
}
Cure &Cure::operator=( const Cure &cur )
{
	if (this != &cur)
	{
		this->_type = cur._type;
	}
	return *this;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

// impl use member function??