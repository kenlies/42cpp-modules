#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure( Cure const & cur );
		~Cure();
		Cure &operator=( const Cure &cur );

		AMateria *clone() const;
};

#endif