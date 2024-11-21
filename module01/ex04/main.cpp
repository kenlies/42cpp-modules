#include "Sed.hpp"

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: bad argument count: usage:" << std::endl;
		std::cerr << "./zed [file] [search] [replace]" << std::endl;
		return 1;
	}
	else
	{
		if (!argv[2][0])
		{
			std::cerr << "Error: bad arguments: can't replace 'nothing'" << std::endl;
			return 1;
		} 
		std::string filename(argv[1]);
		std::string s1(argv[2]);
		std::string s2(argv[3]);
		Sed sedi;
		sedi.replace(filename, s1, s2);
	}
	return 0;
}
