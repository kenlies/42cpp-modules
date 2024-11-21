/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:03:43 by aotsala           #+#    #+#             */
/*   Updated: 2023/10/23 21:40:27 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main (void)
{
	string a = "HI THIS IS BRAIN";
	string *p = &a;
	string &r = a;

	cout << &a << endl;
	cout << p << endl;
	cout << &r << endl;

	cout << a << endl;
	cout << *p << endl;
	cout << r << endl;

	return (0);
}
