#include "ScalarConverter.hpp"

static bool has_allowed_chars(char *argv)
{
	if (strlen(argv) == 1 ||
		!strcmp(argv, "nan") ||
		!strcmp(argv, "nanf") ||
		!strcmp(argv, "+inff") ||
		!strcmp(argv, "-inff") ||
		!strcmp(argv, "+inf") ||
		!strcmp(argv, "-inf"))
		return true;
	for (size_t i = 0; i < strlen(argv); i++)
	{
		if (!isnumber(argv[i]) && argv[i] != 'f' && argv[i] != '.')
			return false;
	}
	return true;
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		if (has_allowed_chars(argv[1]))
			ScalarConverter::convert(argv[1]);
		else
			ScalarConverter::convert("");
	}
	else
	{
		std::cerr << "error: wrong argument count\n";
		return 1;
	}
	return 0;
}