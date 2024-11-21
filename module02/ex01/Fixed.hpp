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