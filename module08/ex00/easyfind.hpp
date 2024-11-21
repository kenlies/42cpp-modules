#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>

template <typename T>
void	easyfind(const T &t, int n)
{
 	auto it = std::find(t.begin(), t.end(), n);
	it != t.end() ? std::cout << "elem: " << *it << " found at index: " << std::distance(t.begin(), it) << "\n"
					: std::cout << "elem: " << n << " not found" << "\n";
}

#endif