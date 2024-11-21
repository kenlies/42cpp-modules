/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/19 07:51:32 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure( Cure const & cur) : AMateria("cure")
{
	*this = cur;
}

Cure::~Cure()
{
}
Cure &Cure::operator=( const Cure &cur )
{
	if (this != &cur)
	{
		this->_type = cur._type;
	}
	return *this;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

// impl use member function??