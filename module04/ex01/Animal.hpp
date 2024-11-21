#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal( std::string type );
		Animal( Animal &anim );
		virtual ~Animal();
		Animal &operator=( const Animal &anim );

		std::string getType() const;
		virtual void makeSound() const;
};

#endif