#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;
	public:
		Dog();
		~Dog();
		Dog( const Dog &dg );
		Dog &operator=( const Dog &dg );
		void makeSound() const;
};

#endif
