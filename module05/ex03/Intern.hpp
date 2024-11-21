
#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentalPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern( const Intern &bur );
		Intern &operator=( const Intern &bur );
		~Intern();

		AForm *makeForm(std::string form_name, std::string target);
};

#endif