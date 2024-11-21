#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int 			_grade_exec;

	public:
		AForm();
		AForm( const std::string name, const int grade_sign, const int grade_exec );
		AForm( const AForm &form );
		AForm &operator=( const AForm &form );
		virtual ~AForm();

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		std::string	getName( void ) const;
		bool		getSigned( void ) const;
		int			getGradeSign( void ) const;
		int			getGradeExec( void ) const;

		virtual void		execute(Bureaucrat const & executor) const = 0;

		virtual void		beSigned( Bureaucrat& bur ) = 0;
};

std::ostream& operator<<( std::ostream& stream, const AForm& form );

#endif