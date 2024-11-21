/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/25 21:29:49 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
	Harl obj;
	obj.complain("DEBUG");
	obj.complain("INFO");
	obj.complain("WARNING");
	obj.complain("ERROR");

	std::cout << std::endl;

	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");

	return 0;
}