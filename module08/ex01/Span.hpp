#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <numeric>
# include <algorithm>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

class Span
{
	public:
		Span();
		Span( unsigned int N );
		Span( const Span &spn );
		Span &operator=( const Span &spn );
		~Span();

		void	addNumber( int num );
		int		shortestSpan( void );
		int		longestSpan( void );
		void 	addRandNumbers( void );

	private:
		std::vector<int>	_nums;
		int					_size;

};


#endif