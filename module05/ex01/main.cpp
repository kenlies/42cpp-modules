#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	Bureaucrat bur("stalin", 2);
	Form fr("form1", 2, 1);

	std::cout << fr;

	try
	{
		fr.beSigned(bur);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << fr;

	return (0);
}