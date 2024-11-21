#include "Span.hpp"

Span::Span() : _size(10)
{
}
Span::Span( unsigned int N ) : _size(N)
{
}

Span::Span( const Span &spn )
{
	*this = spn;
}

Span &Span::operator=( const Span &spn )
{
	if (this != &spn)
	{
		*this = spn;
	}
	return *this;
}

Span::~Span()
{	
}

void Span::addNumber( int num )
{
	_nums.push_back(num);
	if (static_cast<int>(_nums.size()) > _size)
		throw std::out_of_range ("error: max size reached");
}

int	Span::shortestSpan( void )
{
	if (_nums.size() == 0 || _nums.size() == 1)
	{
		throw std::out_of_range ("error: there must be ateast 2 numbers");
		return 0;
	}

	int currMin = INT_MAX;
	int size = _nums.size();
	int holder;

	std::sort(_nums.begin(), _nums.end());

	for (int i = 0; i < size - 1; i++)
	{
		holder = std::abs(_nums[i] - _nums[i + 1]);
		if (holder < currMin)
			currMin = holder;
	}
	return currMin;
}

int	Span::longestSpan( void )
{
	if (_nums.size() == 0 || _nums.size() == 1)
	{
		throw std::out_of_range ("error: there must be ateast 2 numbers");
		return 0;
	}
	auto minmax = std::minmax_element(_nums.begin(), _nums.end());
	return *minmax.second - *minmax.first;
}

static int randNumGen( void )
{
	return (std::rand()%1000);
}

void Span::addRandNumbers( void )
{
	std::srand(time(0));

	std::vector<int> newNums(_size);
	std::generate(newNums.begin(), newNums.end(), randNumGen);
	_nums = newNums;
	std::cout << "generated vector: ";
	for (auto e : _nums)
		std::cout << e << " ";
	std::cout << "\n";
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// this is redundant, but we are forced to use as many algo funcs as possible...
	std::shuffle(_nums.begin(), _nums.end(), std::default_random_engine(seed));
	std::cout << "after shuffle:    ";
	for (auto e : _nums)
		std::cout << e << " ";
	std::cout << "\n";
}