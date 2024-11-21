#include "AMateria.hpp"

AMateria::AMateria() : _type("nothing")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(AMateria const & mater)
{
	*this = mater;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const //Returns the materia type
{
	return this->_type;
}

AMateria* AMateria::clone() const
{
	return ((AMateria*)this);
}

void AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else
		std::cout << "* Materia type is 'nothing': can't use *" << std::endl;
}