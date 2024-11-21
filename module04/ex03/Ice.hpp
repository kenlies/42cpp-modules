#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice( Ice const & ic);
		~Ice();
		Ice &operator=( const Ice &ic );

		AMateria *clone() const;
};

#endif