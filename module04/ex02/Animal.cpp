/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/14 16:54:10 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : _type( "Animal" )
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type(type)
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal &anim)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = anim;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=( const AAnimal &anim)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &anim)
	{
		this->_type = anim._type;
	}
	return *this;
}

std::string AAnimal::getType() const
{
	return this->_type;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << std::endl;
}