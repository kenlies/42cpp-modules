#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class Sed
{
	public:
		void replace(std::string& line, const std::string& s1, const std::string& s2);
};

#endif