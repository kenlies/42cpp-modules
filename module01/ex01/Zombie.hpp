#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using std::string;
using std::cout;
using std::endl;

class Zombie
{	
	public:
		Zombie();
		~Zombie();
		void	announce(void);
		void	setName(string name);
	private:
		string _name;
};

Zombie*		zombieHorde( int N, std::string name );

#endif