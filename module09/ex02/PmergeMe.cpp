#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( int argc, char **argv ) : _argc(argc), _argv(argv)
{
}

PmergeMe::PmergeMe( PmergeMe const & pm )
{
	*this = pm;
}

PmergeMe &PmergeMe::operator=( PmergeMe const & pm )
{
	if (this != &pm)
	{
		*this = pm;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::validateConvertArg( void )
{
	bool is_valid = true;
	std::vector<std::string> args(_argv + 1, _argv + _argc);
	for (auto e : args)
	{
		for (size_t i = 0; i < e.size(); i++)
			if (!isdigit(e[i]))
				is_valid = false;
		if (is_valid)
		{
			try
			{
				_vec_args.push_back(stoi(e));
				_deq_args.push_back(stoi(e));
			}
			catch(const std::exception & e)
			{
				is_valid = false;
			}
		}
	}
	if (!is_valid)
	{
		std::cerr << "Error: invalid values" << std::endl;
		exit(1);
	}
	if (_argc == 2)
	{
		_vec_sequence.push_back(stoi(std::string(_argv[1])));
		_deq_sequence.push_back(stoi(std::string(_argv[1])));
		PmergeMe::print();
		exit(0);
	}
}

void PmergeMe::vecCatchStraggler( void )
{
	_vec_start = std::chrono::high_resolution_clock::now();
	if (_vec_args.size() % 2 == 1)
	{
		_is_straggler = true;
		_straggler = _vec_args.back();
		_vec_args.pop_back();
		return ;
	}
	_is_straggler = false;
}

void PmergeMe::deqCatchStraggler( void )
{
	_is_straggler = false; // turn it back to false after vec
	_deq_start = std::chrono::high_resolution_clock::now();
	if (_deq_args.size() % 2 == 1)
	{
		_is_straggler = true;
		_straggler = _deq_args.back();
		_deq_args.pop_back();
		return ;
	}
	_is_straggler = false;
}

void PmergeMe::vecCreatePairs( void )
{
	int count = 0;

	for (auto e : _vec_args)
	{
		(void)e;
		count++;
		if (count == 2)
		{
			std::vector<int> pair;
			pair.push_back(_vec_args.back());
			_vec_args.pop_back();
			pair.push_back(_vec_args.back());
			_vec_args.pop_back();
			_vec_pairs.push_back(pair);
			count = 0;
		}
	}
}

void PmergeMe::deqCreatePairs( void )
{
	int count = 0;

	for (auto e : _deq_args)
	{
		(void)e;
		count++;
		if (count == 2)
		{
			std::deque<int> pair;
			pair.push_back(_deq_args.back());
			_deq_args.pop_back();
			pair.push_back(_deq_args.back());
			_deq_args.pop_back();
			_deq_pairs.push_back(pair);
			count = 0;
		}
	}
}

void PmergeMe::vecSortEachPair ( void )
{
	for (auto &e : _vec_pairs)
	{
		if (e[0] > e[1])
		{
			int tmp = e[0];
			e[0] = e[1];
			e[1] = tmp;
		}
	}
}

void PmergeMe::deqSortEachPair ( void )
{
	for (auto &e : _deq_pairs)
	{
		if (e[0] > e[1])
		{
			int tmp = e[0];
			e[0] = e[1];
			e[1] = tmp;
		}
	}
}

static void vecInsert(std::vector<int> p, std::vector<std::vector<int>> &pairs, int len)
{
	if (len < 0)
		pairs[0] = p;
	else if (p[1] >= pairs[len][1])
	{
		if ((unsigned long)len == pairs.size() - 1)
			pairs.push_back(p);
		else
			pairs[len + 1] = p;
	}
	else
	{
		if ((unsigned long)len == pairs.size() - 1)
			pairs.push_back(pairs[len]);
		else
		{
			pairs[len + 1] = pairs[len];
			vecInsert(p, pairs, len - 1);
		}
	}
}

static void deqInsert(std::deque<int> p, std::deque<std::deque<int>> &pairs, int len)
{
	if (len < 0)
		pairs[0] = p;
	else if (p[1] >= pairs[len][1])
	{
		if ((unsigned long)len == pairs.size() - 1)
			pairs.push_back(p);
		else
			pairs[len + 1] = p;
	}
	else
	{
		if ((unsigned long)len == pairs.size() - 1)
			pairs.push_back(pairs[len]);
		else
		{
			pairs[len + 1] = pairs[len];
			deqInsert(p, pairs, len - 1);
		}
	}
}

static void vecSortByLargerValueRecursively(std::vector<std::vector<int>> &pairs, int len)
{
	if (len < 0)
		return ;
	else
	{
		vecSortByLargerValueRecursively(pairs, len - 1);
		vecInsert(pairs[len], pairs, len - 1);
	}
}

static void deqSortByLargerValueRecursively(std::deque<std::deque<int>> &pairs, int len)
{
	if (len < 0)
		return ;
	else
	{
		deqSortByLargerValueRecursively(pairs, len - 1);
		deqInsert(pairs[len], pairs, len - 1);
	}
}

void PmergeMe::vecSortByLargerValue( void )
{
	vecSortByLargerValueRecursively(_vec_pairs, _vec_pairs.size() - 1);
}

void PmergeMe::deqSortByLargerValue( void )
{
	deqSortByLargerValueRecursively(_deq_pairs, _deq_pairs.size() - 1);
}

void PmergeMe::vecCreateFinalSequence( void )
{
	std::vector<int> pend;

	for (auto e : _vec_pairs)
	{
		_vec_sequence.push_back(e[1]);
		pend.push_back(e[0]);
	}
	_vec_sequence.insert(_vec_sequence.begin(), pend[0]);
	pend.erase(pend.begin());
	unsigned long iterator = 0;
	int item;
	while (iterator < pend.size())
	{
		item = pend[iterator];
		auto insertion_point = std::upper_bound(_vec_sequence.begin(), _vec_sequence.end(), item);
		_vec_sequence.insert(insertion_point, item);
		iterator++;
	}
	if (_is_straggler)
	{
		auto insertion_point = std::upper_bound(_vec_sequence.begin(), _vec_sequence.end(), _straggler);
		_vec_sequence.insert(insertion_point, _straggler);
	}
	_vec_end = std::chrono::high_resolution_clock::now();
	if (!std::is_sorted(_vec_sequence.begin(), _vec_sequence.end()))
	{
		std::cerr << "Error: final vec sequence not sorted" << std::endl;
		exit(1);
	}
	if (static_cast<unsigned long>(_argc - 1) != _vec_sequence.size())
	{
		std::cerr << "Error: final vec sequence transformed" << std::endl;
		exit(1);
	}
}

void PmergeMe::deqCreateFinalSequence( void )
{
	std::deque<int> pend;

	for (auto e : _deq_pairs)
	{
		_deq_sequence.push_back(e[1]);
		pend.push_back(e[0]);
	}
	_deq_sequence.insert(_deq_sequence.begin(), pend[0]);
	pend.erase(pend.begin());
	unsigned long iterator = 0;
	int item;
	while (iterator < pend.size())
	{
		item = pend[iterator];
		auto insertion_point = std::upper_bound(_deq_sequence.begin(), _deq_sequence.end(), item);
		_deq_sequence.insert(insertion_point, item);
		iterator++;
	}
	if (_is_straggler)
	{
		auto insertion_point = std::upper_bound(_deq_sequence.begin(), _deq_sequence.end(), _straggler);
		_deq_sequence.insert(insertion_point, _straggler);
	}
	_deq_end = std::chrono::high_resolution_clock::now();
	if (!std::is_sorted(_deq_sequence.begin(), _deq_sequence.end()))
	{
		std::cerr << "Error: final deq sequence not sorted" << std::endl;
		exit(1);
	}
	if (static_cast<unsigned long>(_argc - 1) != _deq_sequence.size())
	{
		std::cerr << "Error: final deq sequence transformed" << std::endl;
		exit(1);
	}
}

void PmergeMe::print( void )
{
	std::cout << "Before:   ";
	_argv++;
	while (*_argv)
		std::cout << *_argv++ << " "; 
	std::cout << std::endl;

	std::cout << "After:    ";
	for (auto e : _vec_sequence)
		std::cout << e << " ";
	std::cout << std::endl;

	std::chrono::microseconds vec_duration = std::chrono::duration_cast<std::chrono::microseconds>(_vec_end - _vec_start);
	std::cout << "Time to process a range of " << _argc - 1 << " elements with std::vector : " << vec_duration.count() << " us" << std::endl;

	std::chrono::microseconds deque_duration = std::chrono::duration_cast<std::chrono::microseconds>(_deq_end - _deq_start);
	std::cout << "Time to process a range of " << _argc - 1 << " elements with std::deque  : " << deque_duration.count() << " us" << std::endl;

	//std::cout << "argc: " << _argc - 1 << " final size: " << _vec_sequence.size() << "\n";
}