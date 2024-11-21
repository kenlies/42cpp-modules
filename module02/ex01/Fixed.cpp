#include "Fixed.hpp"

	Fixed::Fixed()
	{
		std::cout << "Default constructor called" << std::endl;
		this->_fpv = 0;
	}

	Fixed::Fixed(const Fixed &fix)
	{
		std::cout << "Copy constructor called" << std::endl;
		*this = fix;
	}

	Fixed::Fixed( const int num_to_fixed )
	{
		std::cout << "Int constructor called" << std::endl;
		this->_fpv = num_to_fixed * (1 << this->_nfb);
	}
	
	Fixed::Fixed( const float num_to_fixed )
	{
		std::cout << "Float constructor called" << std::endl;
		this->_fpv = roundf(num_to_fixed * float(1 << this->_nfb));
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
			this->_fpv = fix._fpv;
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

	float	Fixed::toFloat( void ) const
	{
		return float(this->_fpv / float(1 << this->_nfb));
	}

	int		Fixed::toInt( void ) const
	{
		return int(this->_fpv / (1 << this->_nfb));
	}

	std::ostream& operator<<(std::ostream& stream, const Fixed& fix )
	{
		stream << fix.toFloat();
		return stream;
	}