#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap trap1;
	ClapTrap trap2("trap2");
	
	trap1 = trap2;

	trap1.attack("Donald Trump");
	trap1.takeDamage(5);
	trap1.beRepaired(200);

	return 0;
}