/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/24 21:28:07 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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