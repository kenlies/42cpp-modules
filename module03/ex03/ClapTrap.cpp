/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/07 12:25:05 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
}

ClapTrap::ClapTrap( std::string name )
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
}

ClapTrap::ClapTrap( const ClapTrap& ct )
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = ct;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &ct )
{
	if (this != &ct)
	{
		this->_name = ct._name;
		this->_hp = ct._hp;
		this->_ep = ct._ep;
		this->_ad = ct._ad;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (static_cast<unsigned int>(_ep) <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target 
			  << ", causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	static int alive = 1;

	if (alive)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount
			  << " of damage" << std::endl;
	}
	this->_hp -= amount;
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead" << std::endl;
		this->_hp = 0;
		alive = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_ep -= 1;
	if (this->_ep <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself for "
			  << amount << " of hitpoints" << std::endl;
	this->_hp += amount;
}