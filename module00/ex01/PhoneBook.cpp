#include "PhoneBook.h"

string PhoneBook::alignContact(int i, int j)
{
	string def = "          ";
	string col;

	if (j == 0)
		col = this->contacts[i].getFirstName();
	else if (j == 1)
		col = this->contacts[i].getLastName();
	else if (j == 2)
		col = this->contacts[i].getNickName();
	if (col.length() > 10)
	{
		col = col.substr(0, 9) + ".";
		return col;
	}
	else if (!col.empty())
		return (string(10 - col.length(), ' ') + col);
	return def;
}

void	PhoneBook::displayContact(int index)
{
	cout << "First name: " << contacts[index - 1].getFirstName() << endl;
	cout << "Last name: " << contacts[index - 1].getLastName() << endl;
	cout << "Nickname: " << contacts[index - 1].getNickName() << endl;
	cout << "Phone number: " << contacts[index - 1].getPhoneNumber() << endl;
	cout << "Darkest secret: " << contacts[index - 1].getDarkestSecret() << endl;
}

void	PhoneBook::searchContact(void)
{
	for (int i = 0; i < 8; i++)
	{
		cout << "         " << i + 1;
		for (int j = 0; j < 3; j++)
			cout << "|" << alignContact(i, j);
		cout << "\n";
	}
	while (42)
	{
		int index;

		cout << "Enter index [1-8]: ";
		if (cin >> index)
		{
			if (index >= 1 && index <= 8)
			{
				displayContact(index);
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break ;
			}
			else
				cout << "Invalid index. Please enter a number between 1 and 8." << endl;
		}
		else
		{
			if (cin.eof())
				exit(1);
			cin.clear(); 													// Clear error state
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// Clear the input buffer
			cout << "Invalid input." << endl;
		}
	}
}

void	PhoneBook::addContact(void)
{
	static int	i;
	this->contacts[i++ % 8].initialize();
}
