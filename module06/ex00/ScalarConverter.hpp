
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <limits.h>
# include <float.h>
# include <iomanip>
# include <math.h>

typedef struct s_info
{
	char		t;
	std::string stype;

	char		c;
	int			i;
	float		f;
	double		d;	
}				t_info;

class ScalarConverter
{

	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter &bur );
		ScalarConverter &operator=( const ScalarConverter &bur );
		virtual ~ScalarConverter() = 0;

	public:
		static void	convert( std::string literal );

};

#endif