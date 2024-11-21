#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Hitler"), _grade(1)
{
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &bur )
{
	*this = bur;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &bur )
{
	if (this != &bur)
	{
		this->_grade = bur._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade can not be higher than 1");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade can not be lower than 150");
}

std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void	Bureaucrat::Increment( void )
{
	if (_grade - 1 < 1)
	{
		throw (GradeTooHighException());
	}
	else
	{
		_grade--;
	}
}

void	Bureaucrat::Decrement( void )
{
	if (_grade + 1 > 150)
	{
		throw (GradeTooLowException());
	}
	else
	{
		_grade++;
	}
}

std::ostream& operator<<( std::ostream& stream, const Bureaucrat& bur )
{
	stream << bur.getName();
	stream << ", bureucrat grade ";
	stream << bur.getGrade();
	stream << "\n";
	return stream;
}