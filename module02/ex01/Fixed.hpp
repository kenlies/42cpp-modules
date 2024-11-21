/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/27 21:31:42 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 				_fpv;
		static const int	_nfb = 8;
	public:
		Fixed();
		Fixed( const int num );
		Fixed( const float num );
		Fixed( const Fixed &fix );
		Fixed &operator=( const Fixed &fix );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fix );

#endif