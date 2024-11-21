#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		RPN rpn(argv[1]);
	}
	else
	{
		std::cerr << "Error: invalid argument count" << std::endl;
		return 1;
	}

	return 0;
}