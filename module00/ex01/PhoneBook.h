#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"
# include <iostream>
# include <cstring>
# include <stdlib.h> 
# include <cctype>

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::flush;
using std::endl;

enum Command
{
	ADD, SEARCH, EXIT
};

class PhoneBook
{
	Contact contacts[8];
	string	alignContact(int i, int j);
	void	displayContact(int index);
	
	public:
		void	addContact(void);
		void	searchContact(void);
};

#endif