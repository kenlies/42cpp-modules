#include "Zombie.hpp"

int main (void)
{
	Zombie *horde;

	horde = zombieHorde(5, "horde_1_zombi");
	for(int i = 0; i < 5; i++) horde[i].announce();
	delete[] horde;

	cout << endl;

	horde = zombieHorde(15, "horde_2_zombi");
	for(int i = 0; i < 15; i++) horde[i].announce();
	delete[] horde;

	return (0);
}
