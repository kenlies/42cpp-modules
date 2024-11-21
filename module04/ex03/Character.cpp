#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Global.hpp"

Character::Character() : _name("noname")
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = nullptr;
}

Character::Character(Character const &chr)
{
	*this = chr;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = nullptr;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] != nullptr)
			delete this->slots[i];
	}
}

Character &Character::operator=(Character const &chr)
{
	if (this != &chr)
	{
		this->_name = chr._name;
		for (int i = 0; i < 4; i++)
		{
			this->slots[i] = chr.slots[i]->clone();
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{	
	if (m == NULL)
		return ;
	if (m->getType() == "nothing")
	{
		std::cout << "* Materia is 'nothing': can't equip *" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] == nullptr)
		{
			this->slots[i] = m;
			std::cout << "* " << this->getName() << " equipped [" << m->getType() 
						<< "] to slot " << i << " *" << std::endl;
			return ;
		}
	}
	std::cout << "* no slots available *" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "* Index it out of bounds: can't unequip *" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == idx && this->slots[i] != nullptr)
		{
			std::cout << "* " << this->getName() << " unequipped [" << this->slots[i]->getType() 
						<< "] at slot " << i << " *" << std::endl;
			for (int j = 0; j < 10; j++)
			{
				if (g_onfloor[j] == nullptr)
				{
					g_onfloor[j] = this->slots[i];
					this->slots[i] = nullptr;
					return ;
				}
			}
			std::cout << "* Materias left on floor disappear *" << std::endl;
			for (int j = 0; j < 10; j++)
			{
				delete g_onfloor[j];
				g_onfloor[j] = nullptr;
			}
			g_onfloor[0] = this->slots[i];
			this->slots[i] = nullptr;
			return ;
		}
	}
	std::cout << "* nothing to unequip *" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "* Index it out of bounds: can't use *";
		return ;
	}
	if (this->slots[idx] != nullptr)
		this->slots[idx]->use(target);
	else
		std::cout << "* slot " << idx << " is empty *" << std::endl;
}