#include "PresidentalPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm() : AForm("PresidentalPardonForm", 25, 5)
{
	_target = "osama bin laden";
}

PresidentalPardonForm::PresidentalPardonForm( std::string target )  : AForm("PresidentalPardonForm", 25, 5)
{
	_target = target;
}

PresidentalPardonForm::PresidentalPardonForm( const PresidentalPardonForm & pres )
{
	*this = pres;
}

PresidentalPardonForm::~PresidentalPardonForm()
{
}

PresidentalPardonForm &PresidentalPardonForm::operator=( const PresidentalPardonForm &pres )
{
	if (this != &pres)
	{
		*this = pres;
	}
	return *this;
}

void	PresidentalPardonForm::beSigned( Bureaucrat& bur )
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

void		PresidentalPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == 1)
	{
		if (executor.getGrade() <= this->_grade_exec)
		{
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
		}
		else
		{
			throw(GradeTooLowException());
		}
	}
	else
	{
		throw(FormNotSignedException());
	}
}