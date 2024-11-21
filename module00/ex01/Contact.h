/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:49 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/22 16:26:49 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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