/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/19 19:22:04 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	try
	{
		this->_brain = new Brain();
	}
	catch (std::bad_alloc)
	{
		std::cout << "Cat Brain allocation fail" << std::endl;
	}
}

Cat::Cat( const Cat &ct )
{
	*this = ct;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=( const Cat &ct )
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &ct)
	{
		this->_type = ct._type;
		try
		{
			this->_brain = new Brain();
		}
		catch (std::bad_alloc)
		{
			std::cout << "Cat Brain allocation fail" << std::endl;
		}
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
