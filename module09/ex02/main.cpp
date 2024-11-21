#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	if (argc > 1 )
	{
		PmergeMe johnson(argc, argv);
		johnson.validateConvertArg();

		johnson.vecCatchStraggler();
		johnson.vecCreatePairs();
		johnson.vecSortEachPair();
		johnson.vecSortByLargerValue();
		johnson.vecCreateFinalSequence();

		johnson.deqCatchStraggler();
		johnson.deqCreatePairs();
		johnson.deqSortEachPair();
		johnson.deqSortByLargerValue();
		johnson.deqCreateFinalSequence();

		johnson.print();
	}
	else
	{
		std::cerr << "Error: invalid argument count" << std::endl;
		return 1;
	}
	return 0;
}