/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/11/04 07:21:59 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point( const float n1, const float n2 );
		Point( const Point &pnt );
		Point &operator=( const Point &pnt );
		~Point();
		Fixed getX() const;
		Fixed getY() const;
};