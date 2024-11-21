#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern( const Intern &in )
{
	*this = in;
}
Intern &Intern::operator=( const Intern &in )
{
	if (this != &in)
	{
		*this = in;
	}
	return *this;
}

Intern::~Intern()
{
}

AForm *createPresidentalPardonForm(std::string target)
{
	return new PresidentalPardonForm(target);
}

AForm *createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	// so here we declare an array of function pointers, they return type *Form and take in std::string target
	AForm *(*func_array[3])(std::string target) = {&createShrubberyCreationForm, &createRobotomyRequestForm, &createPresidentalPardonForm};
	std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidental pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == form_names[i])
		{
			std::cout << "Intern creates " << form_name << "\n";
			return (func_array[i](target));
		}
	}
	std::cout << "Intern could not create " << form_name << "\n";
	return NULL;
}
