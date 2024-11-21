#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		std::string	levels[4];
		void (Harl::*func[4])(void);
		void execute( int i);
		void debug( void );
		void info( void );
		void warning ( void );
		void error ( void );
	public:
		void	complain( std::string level);
};

#endif