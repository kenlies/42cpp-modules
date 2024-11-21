#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "cat";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )  : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & shrub )
{
	*this = shrub;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &shrub )
{
	if (this != &shrub)
	{
		*this = shrub;
	}
	return *this;
}

void	ShrubberyCreationForm::beSigned( Bureaucrat& bur )
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

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == 1)
	{
		if (executor.getGrade() <= this->_grade_exec)
		{
			std::ofstream file(this->_target + "_shurbbery");
			for (int i = 0; i < 10; i++)
			{
				file << " _                 " << "\n";
				file << "| |                " << "\n";
				file << "| |_ _ __ ___  ___ " << "\n";
				file << "| __| '__/ _ \\/ _ \\" << "\n";
				file << "| |_| | |  __/  __/" << "\n";
				file << " \\__|_|  \\___|\\___|" << "\n";
			}
			file.close();
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