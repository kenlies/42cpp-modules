#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* mats[4];
	public:
		MateriaSource();
		MateriaSource( MateriaSource const &mat );
		~MateriaSource();
		MateriaSource &operator=( const MateriaSource &mat );

		void learnMateria( AMateria *);
		AMateria *createMateria( std::string const & type);
};

#endif