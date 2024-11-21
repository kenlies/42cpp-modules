/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/19 07:51:38 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice( Ice const & ic) : AMateria("ice")
{
	*this = ic;
}

Ice::~Ice()
{
}
Ice &Ice::operator=( const Ice &ic )
{
	if (this != &ic)
	{
		this->_type = ic._type;
	}
	return *this;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}