/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/04 07:22:04 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point( const float n1, const float n2 ) : _x(n1), _y(n2)
{
}

Point::Point( const Point &pnt ) : _x(pnt._x), _y(pnt._y)
{
}

Point::~Point()
{
}

Point& Point::operator=( const Point &pnt )
{
	if (this != &pnt)
	{
		( Fixed )this->_x = pnt._x;
		( Fixed )this->_y = pnt._y;
	}
	return *this;
}

Fixed Point::getX( void ) const
{
	return (this->_x);
}
Fixed Point::getY( void ) const
{
	return (this->_y);
}