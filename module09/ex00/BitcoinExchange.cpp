#include "BitcoinExchange.hpp"

BitcoinExhange::BitcoinExhange()
{
	initDatabase();
}

BitcoinExhange::BitcoinExhange( const BitcoinExhange & bit )
{
	*this = bit;
}

BitcoinExhange &BitcoinExhange::operator=( const BitcoinExhange & bit )
{
	if (this != &bit)
	{
		*this = bit;
	}
	return *this;
}

BitcoinExhange::~BitcoinExhange()
{
}

void BitcoinExhange::initDatabase( void )
{
	std::ifstream file;
	std::string line;
	file.open("data.csv");
	if (file.is_open())
	{
		getline(file, line);
		while (getline(file, line))
		{
			_database[line.substr(0, 10)] = std::stof(line.substr(11));
		}
/* 		std::map<std::string, float>::iterator itr;
		std::cout << std::fixed << std::setprecision(2);
	    for (itr = _database.begin(); itr != _database.end(); ++itr)
        	std::cout << itr->first << ' ' << itr->second << '\n'; */
    }
	else
	{
		std::cerr << "error: could not open file" << std::endl;
	}
}