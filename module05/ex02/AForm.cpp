#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _grade_sign(1), _grade_exec(1)
{
}

AForm::AForm( const std::string name, const int grade_sign, const int grade_exec ) :
			_name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (this->_grade_sign < 1 || this->_grade_exec < 1)
		throw (GradeTooHighException());
	else if (this->_grade_sign > 150 || this->_grade_exec > 150)
		throw (GradeTooLowException());
}

AForm::AForm( const AForm &form ) : 
	_name(form._name), _signed(form._signed),
	_grade_sign(form._grade_sign), _grade_exec(form._grade_exec)
{
}
AForm &AForm::operator=( const AForm &form )
{
	if (this != &form)
	{
		this->_signed = form._signed;
	}
	return *this;
}

AForm::~AForm()
{
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::string	AForm::getName( void ) const
{
	return this->_name;
}

bool		AForm::getSigned( void ) const
{
	return this->_signed;
}

int			AForm::getGradeSign( void ) const
{
	return this->_grade_sign;
}

int			AForm::getGradeExec( void ) const
{
	return this->_grade_exec;
}

std::ostream& operator<<( std::ostream& stream, const AForm& form )
{
	stream << "FORM INFO: ";
	stream << "name: " << form.getName() << ", ";
	stream << "signed: " << form.getSigned() << ", ";
	stream << "gradesign: " << form.getGradeSign() << ", ";
	stream << "grade-exec: " << form.getGradeExec() << ", ";
	stream << "\n";
	return stream;
}