#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm & shrub );
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &shrub );

		void	beSigned( Bureaucrat& bur );
		void	execute(Bureaucrat const & executor) const;
};

#endif