#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		virtual ~Cat();
		Cat( const Cat &ct );
		Cat &operator=( const Cat &ct );
		void makeSound() const;
};

#endif
