#include "Fixed.hpp"

int	main ( void )
{
	Fixed		a;
	Fixed const b( Fixed( 5.05f) * Fixed( 2 ));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "-------------MY TESTS-------------" << std::endl;

	Fixed 		i ( 10 );
	Fixed const c( 42.42f );

	if (i < b)
		std::cout << "i is smaller" << std::endl;
	else if (i > b)
		std::cout << "i is bigger" << std::endl;

	if (b == c)
		std::cout << "b and c are equal" << std::endl;
	else if (b != c)
		std::cout << "b and c are NOT equal" << std::endl;

 	if (i <= b)
		std::cout << "i is equal or smaller" << std::endl;
	else if (i >= b)
		std::cout << "i is equal or bigger" << std::endl;

	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	Fixed	d( Fixed( 11.2f ) / Fixed( 1.1f ));
	std::cout << d << std::endl;

	Fixed	p( 2.2f );
	Fixed	l( -3.0f );

	std::cout << p - l << std::endl;
	std::cout << p + l << std::endl;
	std::cout << p * l << std::endl;
	std::cout << l * p << std::endl;
	std::cout << p / l << std::endl;
	std::cout << l / p << std::endl;

	std::cout << Fixed::min( p, l ) << std::endl;

	return 0;
}