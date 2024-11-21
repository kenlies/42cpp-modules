
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{
	Intern	someRandomIntern;
	AForm*	rff;

	rff = someRandomIntern.makeForm("robotomy request", "Bender");
	if (!rff)
		exit(1);
	Bureaucrat bur("nazi", 50);
	try
	{
		rff->beSigned(bur);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}
	bur.executeForm(*rff);

	delete rff;

	return (0);
}