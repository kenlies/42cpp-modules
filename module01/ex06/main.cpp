/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/25 18:07:26 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		std::string level = argv[1];
		Harl obj;
		obj.complain(level);
	}
	else
	{
		std::cout << "Error: Bad argument: usage:" << std::endl;
		std::cout << "./harlfilter [option]" << std::endl;
		std::cout << "options: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
	return 0;
}