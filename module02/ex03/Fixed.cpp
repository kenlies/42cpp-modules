#include "Fixed.hpp"

	Fixed::Fixed()
	{
		//std::cout << "Default constructor called" << std::endl;
		this->_fpv = 0;
	}

	Fixed::Fixed(const Fixed &fix)
	{
		//std::cout << "Copy constructor called" << std::endl;
		*this = fix;
	}

	Fixed::Fixed( const int num_to_fixed )
	{
		//std::cout << "Int constructor called" << std::endl;
		this->_fpv = num_to_fixed * (1 << this->_nfb);
	}
	
	Fixed::Fixed( const float num_to_fixed )
	{
		//std::cout << "Float constructor called" << std::endl;
		this->_fpv = roundf(num_to_fixed * static_cast<float>(1 << this->_nfb));
	}

	Fixed::~Fixed()
	{
		//std::cout << "Destructor called" << std::endl;
	}

	Fixed& Fixed::operator=(const Fixed &fix)
	{
		//std::cout << "Copy assignment operator called" << std::endl;
		if (this != &fix)
		{
			this->_fpv = fix._fpv;
		}
		return *this;
	}
	//-----------Arithmetic Operators-----------//
	Fixed& Fixed::operator+( const Fixed &fix )
	{
		this->_fpv += fix._fpv;
		return *this;
	}

	Fixed& Fixed::operator-( const Fixed &fix )
	{
		this->_fpv -= fix._fpv;
		return *this;
	}

	Fixed& Fixed::operator*( const Fixed &fix )
	{
		this->_fpv = (static_cast<long>(fix._fpv) * static_cast<long>(this->_fpv)) >> this->_nfb;
		return *this;
	}

	Fixed& Fixed::operator/( const Fixed &fix )
	{
		this->_fpv = (static_cast<long>(this->_fpv) << this->_nfb) / (fix._fpv);
		return *this;
	}

	//-----------increment/decrement Operators-----------//

	Fixed& Fixed::operator--()
	{
		float smallestIcrement = 1.0 / static_cast<float>(1 << this->_nfb);
		this->_fpv -= static_cast<int>(smallestIcrement * (1 << this->_nfb));
		return *this;
	}

	Fixed& 	Fixed::operator++()
	{
		float smallestIcrement = 1.0 / static_cast<float>(1 << this->_nfb);
		this->_fpv += static_cast<int>(smallestIcrement * (1 << this->_nfb));
		return *this;
	}

	Fixed	Fixed::operator++( int )
	{
		Fixed temp = *this;
	
		float smallestIcrement = 1.0 / static_cast<float>(1 << this->_nfb);
		this->_fpv += static_cast<int>(smallestIcrement * (1 << this->_nfb));
		
		return temp;
	}
	
	Fixed	Fixed::operator--( int )
	{
		Fixed temp = *this;
	
		float smallestIcrement = 1.0 / static_cast<float>(1 << this->_nfb);
		this->_fpv -= static_cast<int>(smallestIcrement * (1 << this->_nfb));
		
		return temp;
	}

	//-----------Comparison Operators-----------//
	bool	Fixed::operator>( const Fixed &fix ) const
	{
		return ((toFloat()) > (fix.toFloat()));
	}

	bool	Fixed::operator<(const Fixed &fix) const
	{
		return ((toFloat()) < (fix.toFloat()));
	}

	bool	Fixed::operator>=( const Fixed &fix ) const
	{

		return ((toFloat()) >= (fix.toFloat()));
	}

	bool	Fixed::operator<=( const Fixed &fix ) const
	{
		return ((toFloat()) <= (fix.toFloat()));
	}

	bool	Fixed::operator==( const Fixed &fix ) const
	{
		return ((toFloat()) == (fix.toFloat()));
	}

	bool	Fixed::operator!=( const Fixed &fix ) const
	{
		return ((toFloat()) != (fix.toFloat()));
	}


	int		Fixed::getRawBits( void ) const
	{
		//std::cout << "getRawBits member function called" << std::endl;
		return this->_fpv;
	}
	void	Fixed::setRawBits( int const raw )
	{
		//std::cout << "setRawBits member function called" << std::endl;
		this->_fpv = raw;
	}

	float	Fixed::toFloat( void ) const
	{
		return static_cast<float>(this->_fpv / static_cast<float>(1 << this->_nfb));
	}

	int		Fixed::toInt( void ) const

	{
		return this->_fpv / (1 << this->_nfb);
	}

	Fixed& Fixed::min(Fixed &a, Fixed &b)
	{
		return (a < b) ? a : b;
	}

	Fixed& Fixed::max(Fixed &a, Fixed &b)
	{
		return (a > b) ? a : b;
	}

	const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
	{
		return (a < b) ? a : b;
	}

	const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
	{
		return (a > b) ? a : b;
	}

	std::ostream& operator<<(std::ostream& stream, const Fixed& fix )
	{
		stream << fix.toFloat();
		return stream;
	}