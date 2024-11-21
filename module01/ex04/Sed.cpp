#include "Sed.hpp"

void	Sed::replace(std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream file1(filename);
	if (!file1.is_open())
	{
		std::cerr << "Error: \"" << filename <<  "\": Unable to open file" << std::endl;
		exit(4);
	}
	else
	{	
		std::string line;

		std::string d_filename = "result.txt";
		std::ofstream file2(d_filename);
		if (!file2.is_open())
		{
			std::cerr << "Error: Unable to create file" << std::endl;
			file1.close();
			exit(5);
		}
		else
		{
			while(std::getline(file1, line, '\0'))
			{
				size_t pos = line.find(s1);
				while (pos != std::string::npos)
				{
					line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
					pos = line.find(s1, pos + s2.length());
				}
				file2 << line;
			}
			file2.close();
		}
		file1.close();
	}
}