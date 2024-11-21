#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int _hp;
		int _ep;
		int _ad;
	public:
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap& ct );
		~ClapTrap();
		ClapTrap &operator=( const ClapTrap &ct );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif 