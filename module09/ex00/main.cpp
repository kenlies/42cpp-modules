#include "BitcoinExchange.hpp"

int getDaysInMonth(int year, int month)
{
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return 29;
		else
			return 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
}

static void executeConversion(std::string line)
{
	BitcoinExhange	bit;
	float			val;

	int years = stoi(line.substr(0, 5));
	int months = stoi(line.substr(5, 2));
	int days = stoi(line.substr(8, 2));

	for (; years > 0; years--)
	{
		for (; months > 0; months--)
		{
			for (; days > 0; days--)
			{
				std::string newDate = std::to_string(years);
				months / 10 < 1 ? newDate = newDate + '-' + '0' + std::to_string(months) : newDate = newDate + '-' + std::to_string(months);
				days / 10 < 1 ? newDate = newDate + '-' + '0' + std::to_string(days) : newDate = newDate + '-' + std::to_string(days);
				bit._it = bit._database.find(newDate);
				if (bit._it != bit._database.end())
				{
					val = stof(line.substr(13));
					std::cout << line.substr(0, 10) <<  " => " << val << " = " << val * bit._it->second << std::endl;
					return ;
				}
			}
			days = getDaysInMonth(years, months);
		}
		months = 12;
	}
	std::cerr << "Error: no date, nor preceeding date found." << std::endl;
}

static bool validateFormat(std::string line)
{
	if (std::count_if( line.begin(), line.end(), []( char c ){return c == '|';}) == 1
		&& std::count_if( line.begin(), line.end(), []( char c ){return c == ' ';}) == 2
		&& line[10] == ' ' && line[12] == ' ' && line[11] == '|')
		return true;
	std::cerr << "Error: bad format." << std::endl;
	return false;
}

static bool validateDate(std::string line)
{
	bool is_valid = true;
	std::string date(line.substr(0, 10));

	//std::cout << "to int: " << stoi(date.substr(5, 2)) << std::endl;
	for (auto e : date)
		if (!isdigit(e) && e != '-')
			is_valid = false;
	if (std::count_if( date.begin(), date.end(), []( char c ){return c == '-';}) != 2)
		is_valid = false;
	if (date[4] != '-' || date[7] != '-')
		is_valid = false;
	try
	{
		int year = stoi(date.substr(0, 5));
		int month = stoi(date.substr(5, 2));
		int day = stoi(date.substr(8, 2));
		if (getDaysInMonth(year, month) < day || day < 1)
			is_valid = false;
		if (month < 1 || month > 12)
		{
			is_valid = false;
		}
		//std::cout << "month: " << month << " day: " << day << std::endl;
	}
	catch (std::exception & e)
	{
		is_valid = false;
	}

	if (is_valid == false)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
	}
	return is_valid;
}

static bool validateVal(std::string line)
{
	bool is_valid = true;
	std::string value(line.substr(13));
	int dot = 0;

	for (auto elem : value)
	{
		if (dot == 1)
			is_valid = true;
		if ((!isdigit(elem) && elem != '.' && elem != '-') || dot > 1 || !is_valid)
		{
			std::cerr << "Error: invalid number." << std::endl;
			return false;
		}
		if (elem == '.')
		{
			is_valid = false;
			dot++;
		}
		if (dot > 1)
		{
			std::cerr << "Error: invalid number." << std::endl;
			return false;
		}
	}
	if (!is_valid)
	{
		std::cerr << "Error: invalid number." << std::endl;
		return false;
	}
	float val;
	try
	{
		val = stof(value);
		if (val < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			is_valid = false;
		}
		else if (val > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			is_valid = false;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: invalid number." << std::endl;
		is_valid = false;
	}
	return is_valid;
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		std::ifstream file;
		file.open(argv[1]);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				if (!line.compare("date | value"))
					continue ;
				if (validateDate(line) && validateFormat(line) && validateVal(line))
				{
					executeConversion(line);
				}
			}
		}
		else
		{
			std::cerr << "Error: could not open file." << std::endl;
			return 2;
		}
	}
	else
	{
		std::cerr << "Error: invalid argument count." << std::endl;
		return 1;
	}
	return 0;
}