#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

using std::string;


class Contact
{
	string	first_name;
	string	last_name;
	string	nick_name;
	string	phone_number;
	string	darkest_secret;
	string	ask(string);
	bool	isStringPrintable(const string& str);
	
	public:
		string	getFirstName(void);
		string	getLastName(void);
		string	getNickName(void);
		string	getPhoneNumber(void);
		string	getDarkestSecret(void);
		void	initialize(void);
};

#endif