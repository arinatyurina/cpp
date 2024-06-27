/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:51:34 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/28 00:11:27 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
	std::cout << "That's a debug message" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "That's an info message" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "That's a warning message" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "That's an error message" << std::endl;
}

void	Harl::complain(std::string level)
{
	
}