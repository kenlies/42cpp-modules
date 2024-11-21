#include "PhoneBook.h"

bool	Contact::isStringPrintable(const string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if(!isprint(str[i]) || str[i] == ' ')
			return false;
	}
	return true;
}

string Contact::ask(string request)
{
	string input;
	bool darkest_secret;

	while (42)
	{
		request.compare("Enter darkest secret: ") ? darkest_secret = false : darkest_secret = true;
		cout << request << "\n" << flush;
		getline(cin, input);
		if (cin.eof())
			exit(1);
		if (input.empty())
		{
			cout << "Invalid input. Please enter a non-empty string."
				 << "\n";
			continue ;
		}
		else if (darkest_secret)
			return input;
		else if (!isStringPrintable(input))
		{
			cout << "Invalid input. Please enter printable characters."
				 << "\n";
			continue ;
		}
		return input;
	}
}

void	Contact::initialize(void)
{
	this->first_name = ask("Enter first name: ");
	this->last_name = ask("Enter last name: ");
	this->nick_name = ask("Enter nickname: ");
	this->phone_number = ask("Enter phone number: ");
	this->darkest_secret = ask("Enter darkest secret: ");
}

string	Contact::getFirstName(void)
{
	return (first_name);
}
string	Contact::getLastName(void)
{
	return (last_name);
}
string	Contact::getNickName(void)
{
	return (nick_name);
}
string	Contact::getPhoneNumber(void)
{
	return (phone_number);
}
string	Contact::getDarkestSecret(void)
{
	return (darkest_secret);
}