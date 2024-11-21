#include "easyfind.hpp"
#include <vector>
#include <array>
#include <list>
#include <set>
#include <stack>

int main()
{
	std::vector<int> vec{1, 2, 3, 4, 5};
	std::array<int, 5> arr{1, 2, 3, 4, 5};
	std::list<int> lst{1, 2, 3, 4, 5};
	std::set<int> set{1, 2, 3, 4, 5};

	std::cout << "vector test: "; easyfind(vec, 1);
	std::cout << "array test: "; easyfind(arr, 2);
	std::cout << "list test: "; easyfind(lst, 3);
	std::cout << "set test: "; easyfind(set, 0);

	return 0;
}