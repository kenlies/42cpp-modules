/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/07 12:43:20 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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