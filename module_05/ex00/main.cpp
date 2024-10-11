/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:07:27 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/30 14:57:22 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	/*Instatiation with an invalide grade*/
	try
	{
		Bureaucrat	John("John", 155);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	Bureaucrat	Alice("Alice", 150);
	try
	{
		Alice.incrementGrade();
		std::cout << Alice;
		Alice.decrementGrade();
		std::cout << Alice;
		Alice.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
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