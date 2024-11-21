/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/07 12:45:05 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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