#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal( std::string type );
		AAnimal( AAnimal &anim );
		virtual ~AAnimal();
		AAnimal &operator=( const AAnimal &anim );

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif