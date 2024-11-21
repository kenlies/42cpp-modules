#include "iter.hpp"

template<typename T>
void printElement(T const &element) 
{
    std::cout << element << " ";
}

void printElem(char const &elem)
{
	std::cout << elem << " ";
}


int main() {

	char charArr[] = {'a', 'b', 'c', 'd'};
	::iter(charArr, 4, printElem);

	std::cout << "\n";

    int intArr[] = {1, 2, 3, 4, 5};
    ::iter(intArr, 5, printElement);

	std::cout << "\n";

    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    ::iter(doubleArr, 5, printElement);

    return 0;
}