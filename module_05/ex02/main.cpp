/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:07:27 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/01 18:18:41 by atyurina         ###   ########.fr       */
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
		ShrubberyCreationForm	shrub("meow");
		Form	buy("buy", 25, 15);
		/*Instatiation with an invalide grade*/
		//Form	play("play", 255, 241);
		Mary.signForm(rent);
		Mary.signForm(buy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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