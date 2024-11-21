#include "Harl.hpp"

int main (void)
{
	Harl obj;
	obj.complain("DEBUG");
	obj.complain("INFO");
	obj.complain("WARNING");
	obj.complain("ERROR");

	std::cout << std::endl;

	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");
	obj.complain("ERROR");

	return 0;
}