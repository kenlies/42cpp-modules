
#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <time.h>

class PresidentalPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentalPardonForm();
		PresidentalPardonForm( std::string target );
		PresidentalPardonForm( const PresidentalPardonForm & pres );
		~PresidentalPardonForm();
		PresidentalPardonForm &operator=( const PresidentalPardonForm &pres );

		void	beSigned( Bureaucrat& bur );
		void	execute(Bureaucrat const & executor) const;
};

#endif