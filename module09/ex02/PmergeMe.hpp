#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <algorithm>
# include <chrono>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe( int argc, char **argv );
		PmergeMe( PmergeMe const & pm );
		PmergeMe &operator=( PmergeMe const & pm );
		~PmergeMe();
		
		void validateConvertArg( void );

		void vecCatchStraggler( void );
		void vecCreatePairs( void );
		void vecSortEachPair ( void );
		void vecSortByLargerValue( void );
		void vecCreateFinalSequence( void );

		void deqCatchStraggler( void );
		void deqCreatePairs( void );
		void deqSortEachPair ( void );
		void deqSortByLargerValue( void );
		void deqCreateFinalSequence( void );

		void print( void );

	private:
		int								_argc;
		char							**_argv;
		std::vector<int>				_vec_args;
		std::deque<int>					_deq_args;

		std::vector<std::vector<int>>	_vec_pairs;
		std::deque<std::deque<int>>		_deq_pairs;

		std::vector<int>				_vec_sequence;
		std::deque<int>					_deq_sequence;
		
		bool _is_straggler;
		int _straggler;
		
		std::chrono::time_point<std::chrono::high_resolution_clock> _vec_start;
		std::chrono::time_point<std::chrono::high_resolution_clock> _vec_end;

		std::chrono::time_point<std::chrono::high_resolution_clock> _deq_start;
		std::chrono::time_point<std::chrono::high_resolution_clock> _deq_end;
};

#endif