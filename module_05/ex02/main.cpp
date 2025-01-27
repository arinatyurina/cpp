/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:07:27 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/27 13:46:46 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat	Mary("Mary", 30);
		Bureaucrat	James("James", 40);
		ShrubberyCreationForm	shrub("target1");
		RobotomyRequestForm	rob("target2");
		PresidentalPardonForm	pres("target3");

		Mary.signForm(shrub);
		Mary.signForm(rob);
		James.signForm(pres);
		Mary.executeForm(shrub);
		Mary.executeForm(rob);
		James.executeForm(pres);
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