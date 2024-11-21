#include "Array.hpp"
#include <iostream>

int main ()
{
	Array<int> arr;
	std::cout << "empty size: " << arr.size() << std::endl;

	std::cout << std::endl;

	Array<int> arr1(5);
	Array<int> arr2(5);

	for (unsigned int  i = 0; i < arr1.size(); i++)
	{
		arr1[i] = i + 1;
		arr2[i] = i + 2;
	}
	
	// test out of bounds
	try
	{
		std::cout << arr1[0] << "-";
		std::cout << arr1[1] << "-";
		std::cout << arr1[2] << "-";
		std::cout << arr1[3] << "-";
		std::cout << arr1[4] << "-";
		std::cout << arr1[5] << "-";
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;


	// test copy assignment
	for (unsigned int i = 0; i < arr1.size(); i++)
	{
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	for (unsigned int  i = 0; i < arr2.size(); i++)
	{
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
	arr1 = arr2;
	std::cout << std::endl;
	for (unsigned int  i = 0; i < arr1.size(); i++)
	{
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	for (unsigned int  i = 0; i < arr2.size(); i++)
	{
		std::cout << arr2[i] << " ";
	}
	return 0;
}