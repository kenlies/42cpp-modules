#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter &scal )
{
	*this = scal;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &scal )
{
	if (this != &scal)
	{
		*this = scal;
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

template<typename T>
static void convertChar ( t_info &io, T convFrom )
{
	if (convFrom < 0 || convFrom > 127 || !io.stype.empty())
	{
		std::cout << "impossible";
		return ;
	}
	if (convFrom < 32 || convFrom > 126)
	{
		std::cout << "Non displayable";
		return ;
	}
	io.c = static_cast<char>(convFrom);
	std::cout << io.c;
}

template<typename T>
static void convertInt ( t_info &io, T convFrom )
{
	if (!io.stype.empty() || convFrom > INT_MAX || convFrom < INT_MIN)
	{
		std::cout << "impossible";
		return ;
	}
	io.i = static_cast<int>(convFrom);
	std::cout << io.i;
}

template<typename T>
static void convertFloat ( t_info &io, T convFrom )
{
	if (!io.stype.empty())
	{
		std::cout << "impossible";
		return ;
	}
	io.f = static_cast<float>(convFrom);
	fmod(io.f, 1.0) == 0.0 ? std::cout << std::fixed << std::setprecision(1) << io.f << "f" : std::cout << io.f << "f";
}

template<typename T>
static void convertDouble ( t_info &io, T convFrom  )
{
	if (!io.stype.empty())
	{
		std::cout << "impossible";
		return ;
	}
	io.d = static_cast<double>(convFrom);
	fmod(io.d, 1.0) == 0.0 ? std::cout << std::fixed << std::setprecision(1) << io.d : std::cout << io.d;
}

static void	printStuff( t_info &io )
{
	if (io.t == 'c')
	{
		io.stype.empty() ? std::cout << "char: " << io.c << "\n" : std::cout << "char: " << io.stype << "\n";
		std::cout << "int: "; convertInt(io, io.c); std::cout << "\n";
		std::cout << "float: "; convertFloat(io, io.c); std::cout << "\n";
		std::cout << "double: "; convertDouble(io, io.c); std::cout << "\n";
	}
	else if (io.t == 'i')
	{
		std::cout << "char: "; convertChar(io, io.i); std::cout << "\n";
		io.stype.empty() ? std::cout << "int: " << io.i << "\n" : std::cout << "int: " << io.stype << "\n";
		std::cout << "float: "; convertFloat(io, io.i); std::cout << "\n";
		std::cout << "double: "; convertDouble(io, io.i); std::cout << "\n";
	}
	else if (io.t == 'f')
	{
		std::cout << "char: "; convertChar(io, io.f); std::cout << "\n";
		std::cout << "int: "; convertInt(io, io.f); std::cout << "\n";
		if (io.stype.empty())
		{
			std::cout << "float: ";
			fmod(io.f, 1.0) == 0.0 ? std::cout << std::fixed << std::setprecision(1) << io.f << "f" << "\n" : std::cout << io.f << "f" << "\n";
		}
		else
			std::cout << "float:" << io.stype << "\n";
		std::cout << "double: "; convertDouble(io, io.f); std::cout << "\n";
	}
	else if (io.t == 'd')
	{
		std::cout << "char: "; convertChar(io, io.d); std::cout << "\n";
		std::cout << "int: "; convertInt(io, io.d); std::cout << "\n";
		std::cout << "float: "; convertFloat(io, io.d); std::cout << "\n";
		io.stype.empty() ? std::cout << "double: " << io.d << "\n" : std::cout << "double:" << io.stype << "\n";
	}
	else if (io.t == 'p')
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: ";
		io.stype == "nanf" || io.stype == "-inff" || io.stype == "+inff" ? 
			std::cout << io.stype << "\n" : std::cout << io.stype << "f" << "\n";
		std::cout << "double: ";
		io.stype == "nanf" || io.stype == "-inff" || io.stype == "+inff" ? 
			std::cout << io.stype.substr(0, io.stype.length() - 1) << "\n" : std::cout << io.stype << "\n";
	}
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}

static bool	findOnceInCorrectPlace( std::string literal, char ch )
{
	if (ch == 'f')
	{
		if (std::count_if( literal.begin(), literal.end(), []( char c ){return c == 'f';}) == 1
			&& literal.back() == 'f')
			return true;
	}
	else if (ch == '.')
	{
		if (std::count_if( literal.begin(), literal.end(), []( char c ){return c == '.';}) == 1
			&& literal.front() != '.' && literal.back() != '.')
		{
			if (literal.find('f') != std::string::npos && literal[literal.size() - 2] == '.')
				return false;
			return true;
		}
	}
	return false;
}

static void convertVal( t_info &io, std::string literal )
{
	try
	{
		if (io.t == 'c')
			io.c = literal[0];
		else if (io.t == 'i')
			io.i = stoi(literal);
		else if (io.t == 'f')
			io.f = stof(literal);
		else if (io.t == 'd')
			io.d = stod(literal);
		else if (io.t == 'p')
			return ;
		else
			io.stype = "impossible";
	}
	catch (std::exception const& e)
	{
		io.stype = "impossible";
	}
}

static bool checkPseudoLiterals( std::string literal, t_info &io )
{
	if (!literal.compare("nan"))
		io.stype = "nan";
	else if (!literal.compare("nanf"))
		io.stype = "nanf";
	else if (!literal.compare("+inff"))
		io.stype = "+inff";
	else if (!literal.compare("-inff"))
		io.stype = "-inff";
	else if (!literal.compare("+inf"))
		io.stype = "+inf";
	else if (!literal.compare("-inf"))
		io.stype = "-inf";
	if (io.stype.empty())
		return false;
	return true;
}

void	ScalarConverter::convert( std::string literal )
{
	t_info io = (t_info){};
	// detect type
	if (literal.size() == 0);
	else if (checkPseudoLiterals(literal, io))
		io.t = 'p';
	else if (literal.size() == 1 && !isdigit(literal[0]))
		io.t = 'c';
	else if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
		io.t = 'i';
	else if (findOnceInCorrectPlace(literal, '.') && findOnceInCorrectPlace(literal, 'f'))
		io.t = 'f';
	else if (findOnceInCorrectPlace(literal, '.') && literal.find('f') == std::string::npos)
		io.t = 'd';
	// convert it from string to its actual type
	convertVal(io, literal);
	// print and convert to other types
	printStuff(io);
}