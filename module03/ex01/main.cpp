#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap scavtrap1;
	ScavTrap scavtrap2("scav2");

	scavtrap1 = scavtrap2;

	scavtrap1.attack("hellokitty");
	scavtrap1.takeDamage(1);
	scavtrap1.beRepaired(5);
	scavtrap1.guardGate();
	
	return 0;
}