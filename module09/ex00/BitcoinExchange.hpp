#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <ctime>

class BitcoinExhange
{
	public:
		BitcoinExhange();
		BitcoinExhange( const BitcoinExhange & bit );
		BitcoinExhange &operator=( const BitcoinExhange & bit );
		~BitcoinExhange();
		std::map<std::string, float> _database;
		std::map<std::string, float>::iterator _it;
	private:
		void initDatabase( void );
};

#endif