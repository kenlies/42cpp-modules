#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		virtual ~Dog();
		Dog( const Dog &dg );
		Dog &operator=( const Dog &dg );
		void makeSound() const;
};

#endif
