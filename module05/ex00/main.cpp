/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2024/01/13 19:10:50 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat bur("stalin", 1);

	std::cout << bur;
	try
	{
		bur.Decrement();
		std::cout << bur;
		bur.Increment();
		std::cout << bur;
		bur.Increment();
		std::cout << bur;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "----------------------------------\n";

	Bureaucrat burra = bur;

	try
	{
		bur.Increment();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "----------------------------------\n";

	try
	{
		Bureaucrat("Bitch", 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	return (0);
}