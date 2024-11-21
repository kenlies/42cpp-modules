#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

class Character : public ICharacter
{
	private:
		AMateria *slots[4];
		std::string _name;
	public:
		Character();
		Character(std::string name);
		Character(Character const &chr);
		~Character();
		Character &operator=(Character const &chr);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif