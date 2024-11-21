#include "Span.hpp"

int main()
{
	Span s(10);

	try 
	{
/*  		s.addNumber(6);
		s.addNumber(3);
		s.addNumber(17);
		s.addNumber(9);
		s.addNumber(11); */
		s.addRandNumbers();
		int span = s.shortestSpan();
		std::cout << "shortest span:    " << span << "\n";
		span = s.longestSpan();
		std::cout << "longest span:     " << span << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	return 0;
}