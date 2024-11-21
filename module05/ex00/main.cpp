#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat bur("stalin", 1);

	std::cout << bur;
	try
	{
		bur.Decrement();
		std::cout << bur;
		bur.Increment();
		std::cout << bur;
		bur.Increment();
		std::cout << bur;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "----------------------------------\n";

	Bureaucrat burra = bur;

	try
	{
		bur.Increment();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "----------------------------------\n";

	try
	{
		Bureaucrat("Bitch", 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	return (0);
}