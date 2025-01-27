/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:07:27 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/27 13:33:32 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	Mary("Mary", 30);
		Form	rent("rent", 35, 25);
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