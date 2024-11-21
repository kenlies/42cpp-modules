#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if ((unsigned int)_ep <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target 
			  << ", causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << this->_name << " is now in guard mode" << std::endl;
}