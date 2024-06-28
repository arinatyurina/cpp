/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:51:34 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/28 14:00:22 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nThat's a debug message\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nThat's an info message\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nThat's a warning message\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThat's an error message" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*func_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	lev = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == message[i])
			lev = i;
	}
	switch (lev)
	{
	case 0:
		(this->*func_ptr[0])();
	case 1:
		(this->*func_ptr[1])();
	case 2:
		(this->*func_ptr[2])();
	case 3:
		(this->*func_ptr[3])();
		break;
	default:
		std::cout << "Wrong input" << std::endl;
		break;
	}
}