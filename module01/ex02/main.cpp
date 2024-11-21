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
