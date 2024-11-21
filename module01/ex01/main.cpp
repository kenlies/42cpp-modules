/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/25 20:44:25 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
