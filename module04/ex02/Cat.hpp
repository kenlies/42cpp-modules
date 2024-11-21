#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public AAnimal
{
	private:
		Brain *_brain;
	public:
		Cat();
		~Cat();
		Cat( const Cat &ct );
		Cat &operator=( const Cat &ct );
		void makeSound() const;
};

#endif
