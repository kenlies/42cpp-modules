#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _grade_sign(1), _grade_exec(1)
{
}

Form::Form( const std::string name, const int grade_sign, const int grade_exec ) :
			_name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (this->_grade_sign < 1 || this->_grade_exec < 1)
		throw (GradeTooHighException());
	else if (this->_grade_sign > 150 || this->_grade_exec > 150)
		throw (GradeTooLowException());
}

Form::Form( const Form &form ) : 
	_name(form._name), _signed(form._signed),
	_grade_sign(form._grade_sign), _grade_exec(form._grade_exec)
{
}
Form &Form::operator=( const Form &form )
{
	if (this != &form)
	{
		this->_signed = form._signed;
	}
	return *this;
}

Form::~Form()
{
}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::string	Form::getName( void ) const
{
	return this->_name;
}

bool		Form::getSigned( void ) const
{
	return this->_signed;
}

int			Form::getGradeSign( void ) const
{
	return this->_grade_sign;
}

int			Form::getGradeExec( void ) const
{
	return this->_grade_exec;
}

void		Form::beSigned( Bureaucrat &bur )
{
	if (bur.getGrade() <= this->_grade_sign)
	{
		bur.signForm(1, *this);
		this->_signed = true;
	}
	else
	{
		bur.signForm(0, *this);
		throw(GradeTooLowException());
	}
}

std::ostream& operator<<( std::ostream& stream, const Form& form )
{
	stream << "FORM INFO: ";
	stream << "name: " << form.getName() << ", ";
	stream << "signed: " << form.getSigned() << ", ";
	stream << "gradesign: " << form.getGradeSign() << ", ";
	stream << "grade-exec: " << form.getGradeExec() << ", ";
	stream << "\n";
	return stream;
}