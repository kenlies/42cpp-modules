#include "Zombie.hpp"

int main (void)
{
	Zombie *zombi = newZombie("zombi1");
	zombi->announce();
	delete zombi;
	randomChump("zombi2");

	return (0);
}
