/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:49 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/22 14:13:05 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

int main ()
{
	string	user_input;
	Command user_command;
	PhoneBook phone_book;

	while (42)
	{
		cout << "commands: ADD, SEARCH & EXIT" << endl;
		cout << "> ";
		getline(cin, user_input);
		
		if (user_input == "ADD")
			user_command = ADD;
		else if (user_input == "SEARCH")
			user_command = SEARCH;
		else if (user_input == "EXIT")
			user_command = EXIT;
		else if (cin.eof())
			exit(1);
		else
			continue ;

		switch (user_command)
		{
			case ADD:
				phone_book.addContact();
				break ;
			case SEARCH:
				phone_book.searchContact();
				break ;
			case EXIT:
				exit(0);
		}
		cin.sync();
	}
	return (0);
}