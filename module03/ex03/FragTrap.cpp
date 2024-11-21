/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/06 17:24:33 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}
FragTrap::~FragTrap ()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
void FragTrap::attack(const std::string& target)
{
	if ((unsigned int)_ep <= 0)
	{
		std::cout << "FragTrap " << _name << " has no energy left!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target 
			  << ", causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 1;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " wants to highfive!" << std::endl;
}