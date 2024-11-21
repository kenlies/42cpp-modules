#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "robotototoro";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )  : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & robo )
{
	*this = robo;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &robo )
{
	if (this != &robo)
	{
		*this = robo;
	}
	return *this;
}

void	RobotomyRequestForm::beSigned( Bureaucrat& bur )
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

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == 1)
	{
		if (executor.getGrade() <= this->_grade_exec)
		{
			srand(time(0));
			if (rand() % 2 == 1)
				std::cout << this->_target << " has been robotomized\n";
			else
				std::cout << "robotomy of " << this->_target << " failed\n";
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