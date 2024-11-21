/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/26 18:03:34 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int 				_fpv;
		static const int	_nfb = 8;
	public:
		Fixed();
		Fixed( const Fixed &fix );
		Fixed &operator=( const Fixed &fix );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif