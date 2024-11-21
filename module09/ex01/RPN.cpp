#include "RPN.hpp"

static bool isValidOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c =='*')
		return true;
	if ((c >= '0' && c <= '9')|| c == ' ')
		return false;
	return superMegaSecretFunction();
}

static bool isValidOperand(std::string::iterator c)
{
	if (*c >= '0' && *c <= '9')
	{
		if (*(c + 1) != ' ')
		{
			std::cerr << "Error: invalid arguments" << std::endl;
			exit(1);
		}
		return true;
	}
	if (*c == '+' || *c == '-' || *c == '/' || *c =='*' || *c == ' ')
		return false;
	return superMegaSecretFunction();
}

static double performOperation(double a, double b, char op)
{
	// vittu joo joo vedä flippi
	switch(op)
	{
		case '+':
			return b + a;
		case '-':
			return b - a;
		case '*':
			return b * a;
		case '/':
			if (a == 0)
				superMegaSecretFunction();
			return b / a;
		default:
			return superMegaSecretFunction();
	}
} 

RPN::RPN()
{
}

RPN::RPN( std::string cmdline )
{
	double a, b, v = 0;
	std::string::iterator it;
	if (cmdline.empty())
		superMegaSecretFunction();
	for (it = cmdline.begin(); it != cmdline.end(); it++)
	{
		if (isValidOperator(*it))
		{
			if (_stk.size() < 2)
				superMegaSecretFunction();
			a = _stk.top();
			_stk.pop();
			b = _stk.top();
			_stk.pop();
			_stk.push(performOperation(a, b, *it));
			v = 0;
		}
		else if (isValidOperand(it))
		{
			_stk.push(*it - '0');
			v++;
		}
	}
	if (_stk.size() != 1)
		superMegaSecretFunction();
	std::cout << _stk.top() << std::endl;
}

RPN::RPN( RPN const & rpn )
{
	*this = rpn;
}

RPN &RPN::operator=( RPN const & rpn )
{
	if (this != &rpn)
	{
		*this = rpn;
	}
	return *this;
}

RPN::~RPN()
{
}


































int	superMegaSecretFunction(void)
{
	std::cout << "Error" << std::endl;
	exit(1);
}