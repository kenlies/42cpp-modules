#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "default";
}

Zombie::~Zombie()
{
	cout << _name << ": " << "Royh royh and I'm dead" << endl;
}

void	Zombie::announce(void)
{
	cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << endl;
}

void	Zombie::setName(string name)
{
	this->_name = name;
}