#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <map>
# include <functional>

class Harl
{
	private:
		std::string	levels[4];
		void (Harl::*func[4])(void);
		void debug( void );
		void info( void );
		void warning ( void );
		void error ( void );
	public:
		void	complain( std::string level);
};

#endif