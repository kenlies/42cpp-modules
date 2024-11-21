#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

int main ()
{
/* 	// shrubbery
	Bureaucrat bur("hitler", 137);
	ShrubberyCreationForm shrub("leningrad");

	try
	{
		shrub.beSigned(bur);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	bur.executeForm(shrub); */

/*  // roboto
	Bureaucrat bur("stalin", 72);
	RobotomyRequestForm robo("pikachu");
	
	try
	{
		robo.beSigned(bur);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	bur.executeForm(robo); */

	Bureaucrat bur("zedong", 26);
	PresidentalPardonForm pres;

	try
	{
		pres.beSigned(bur);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	bur.executeForm(pres);


	return (0);
}