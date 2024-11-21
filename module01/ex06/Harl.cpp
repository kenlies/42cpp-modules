#include "Harl.hpp"

void	Harl::execute( int i )
{
	switch (i)
	{
		case 0:
			(this->*func[0])();
		case 1:
			(this->*func[1])();
		case 2:
			(this->*func[2])();
		default:
			(this->*func[3])();
			exit(0);
	}
}

void	Harl::complain( std::string level)
{
	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	
	for (int i = 0; i < 5; i++)
	{
		levels[i].compare(level) ? void() : execute(i);
		i == 4 ? std::cout << "[ Probably complaining about insignificant problems ]" << std::endl : std::cout << "";
	}
}

void Harl::debug( void )
{
	std::cout << "(DEBUG): ";
	std::cout << "I love having extra bacon for my "
				"7XL-double-cheese-triple-pickle-specialketchup burger. "
				"I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "(INFO): ";
	std::cout << "I cannot believe adding extra bacon costs more money. "
				"You didn't putenough bacon in my burger! If you did, "
				"I wouldn't be asking for more!" << std::endl;
}
void Harl::warning ( void )
{
	std::cout << "(WARNING): ";
	std::cout << "I think I deserve to have some extra bacon for free. "
				"I've been coming for years whereas you started working "
				"here since last month." << std::endl;
}
void Harl::error ( void )
{
	std::cout << "(ERROR): ";
	std::cout << "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}
