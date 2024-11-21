#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat &bur );
		Bureaucrat &operator=( const Bureaucrat &bur );
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		std::string	getName( void ) const;
		int			getGrade( void ) const;

		void	Increment( void );
		void	Decrement( void );

		void	signForm( int status, const Form &form);
};

std::ostream& operator<<( std::ostream& stream, const Bureaucrat& bur );

#endif