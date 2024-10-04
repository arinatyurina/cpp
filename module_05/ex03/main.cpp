/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:07:27 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/04 20:38:51 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Bureaucrat	Mary("Mary", 30);
		Bureaucrat	James("James", 40);

		Intern	intern;
		Form	*f1 = intern.makeForm("shrubbery creation", "target1");
		Form	*f2 = intern.makeForm("robotomy request", "target2");
		Form	*f3 = intern.makeForm("presidental pardon", "target3");
		Form	*f4 = intern.makeForm("noname", "target4");
		Mary.signForm(*f1);
		James.executeForm(*f1);
		delete(f1);
		delete(f2);
		delete(f3);
		delete(f4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: "<< e.what() << '\n';
	}
}

/*
Exception are used to handle errors during execution
throw is redundant (it breaks the executioin of function)
try
{
	code to be executed
}
catch (type of exception - const char* mes)
{
	cout << mes << endl;
}
catch(...){} - handling any type of exception
 */