#include "FragTrap.hpp"

int main (void)
{
	FragTrap fragtrap1;
	FragTrap fragtrap2("frag2");

	fragtrap1 = fragtrap2;

	fragtrap1.attack("hellokitty");
	fragtrap1.takeDamage(1);
	fragtrap1.beRepaired(5);
	fragtrap1.highFivesGuys();
	
	return 0;
}