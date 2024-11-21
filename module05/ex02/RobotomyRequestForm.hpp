#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <time.h>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm & robo );
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=( const RobotomyRequestForm &robo );

		void	beSigned( Bureaucrat& bur );
		void	execute(Bureaucrat const & executor) const;
};

#endif