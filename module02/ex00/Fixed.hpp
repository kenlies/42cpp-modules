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