#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>

int	superMegaSecretFunction(void);

class RPN
{
	public:
		RPN();
		RPN( std::string cmdline );
		RPN( RPN const & rpn );
		RPN &operator=( RPN const & rpn );
		~RPN();
	private:
		std::stack<double> _stk;
};

#endif