#include "Zombie.hpp"

Zombie::Zombie(string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	cout << _name << ": " << "Royh royh and I'm dead" << endl;
}

void	Zombie::announce(void)
{
	cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << endl;
}