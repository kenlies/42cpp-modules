#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->mats[i] = nullptr;
}

MateriaSource::MateriaSource( MateriaSource const &mat )
{
	*this = mat;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mats[i] != nullptr)
			delete this->mats[i];
	}
}

MateriaSource &MateriaSource::operator=( const MateriaSource &mat )
{
	if (this != &mat)
	{
		for (int i = 0; i < 4; i++)
		{
			this->mats[i] = mat.mats[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria( AMateria *mat )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mats[i] == nullptr)
		{
			this->mats[i] = mat;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria( std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mats[i] != nullptr && mats[i]->getType() == type)
		{
			return this->mats[i]->clone();
		}
	}
	std::cout << "* error: '" << type << "': no such Materia: can't create *" << std::endl;
	return NULL;
}
