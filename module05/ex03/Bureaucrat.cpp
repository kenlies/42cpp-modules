
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
		*this = bur;
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

void	Bureaucrat::signForm( int status, const AForm &form )
{
	if (status)
		std::cout << this->getName() << " signed " << form.getName() << "\n";
	else
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() <<
			" because they don't meet the grade requirement\n";
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "\n";
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "thus, " << this->getName() << " could not execute " << form.getName() << "\n";
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