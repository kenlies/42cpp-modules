/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/24 21:27:40 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using std::string;
using std::cout;
using std::endl;

class Zombie
{	
	public:
		Zombie(string name);
		~Zombie();
		void	announce(void);
	private:
		string _name;
};

Zombie *newZombie( std::string name );
void	randomChump( std::string name );

#endif