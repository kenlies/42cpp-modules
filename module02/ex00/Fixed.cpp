/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/26 18:03:40 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	Fixed::Fixed()
	{
		std::cout << "Default constructor called" << std::endl;
		this->_fpv = 0;
	}

	Fixed::Fixed(const Fixed &fix)
	{
		std::cout << "Copy constructor called" << std::endl;
		this->_fpv = fix.getRawBits();
	}

	Fixed::~Fixed()
	{
		std::cout << "Destructor called" << std::endl;
	}

	Fixed& Fixed::operator=(const Fixed &fix)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		if (this != &fix)
		{
			this->_fpv = fix.getRawBits();
		}
		return *this;
	}

	int		Fixed::getRawBits( void ) const
	{
		std::cout << "getRawBits member function called" << std::endl;
		return this->_fpv;
	}
	void	Fixed::setRawBits( int const raw )
	{
		std::cout << "setRawBits member function called" << std::endl;
		this->_fpv = raw;
	}