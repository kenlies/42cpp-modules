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
		~Fixed();
		Fixed &operator=( const Fixed &fix );
		Fixed operator+( Fixed &fix );
		Fixed operator-( Fixed &fix );
		Fixed operator*( const Fixed &fix );
		Fixed operator/( const Fixed &fix );
		
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++( int );
		Fixed operator--( int );
		
		bool	operator>( const Fixed &fix ) const;
		bool	operator<( const Fixed &fix ) const;
		bool	operator>=( const Fixed &fix ) const;
		bool	operator<=( const Fixed &fix ) const;
		bool	operator==( const Fixed &fix ) const;
		bool	operator!=( const Fixed &fix ) const;
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static	Fixed &min(Fixed &a, Fixed &b);
		static	Fixed &max(Fixed &a, Fixed &b); 
		static	const Fixed &min(const Fixed &a, const Fixed &b);
		static	const Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream& operator<<(std::ostream& stream, const Fixed& fix );

#endif