/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/24 23:01:29 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>
#include "Harl.hpp"

void	Harl::complain( std::string level)
{
	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	
	for (int i = 0; i < 4; i++)
		levels[i].compare(level) ? void() : (this->*func[i])();
}

void Harl::debug( void )
{
	std::cout << "(DEBUG): ";
	std::cout << "I love having extra bacon for my "
				"7XL-double-cheese-triple-pickle-specialketchup burger. "
				"I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "(INFO): ";
	std::cout << "I cannot believe adding extra bacon costs more money. "
				"You didn’t putenough bacon in my burger! If you did, "
				"I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning ( void )
{
	std::cout << "(WARNING): ";
	std::cout << "I think I deserve to have some extra bacon for free. "
				"I’ve been coming for years whereas you started working "
				"here since last month." << std::endl;
}
void Harl::error ( void )
{
	std::cout << "(ERROR): ";
	std::cout << "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}