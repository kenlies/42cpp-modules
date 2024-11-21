#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int 			_grade_exec;

	public:
		Form();
		Form( const std::string name, const int grade_sign, const int grade_exec );
		Form( const Form &form );
		Form &operator=( const Form &form );
		~Form();

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
		bool		getSigned( void ) const;
		int			getGradeSign( void ) const;
		int			getGradeExec( void ) const;

		void		beSigned( Bureaucrat& bur );
};

std::ostream& operator<<( std::ostream& stream, const Form& form );

#endif