/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:51:29 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/28 13:19:28 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	h;
	std::cout << "This program allows you to pring different messages." << std::endl;
	std::cout << "You can ask for a DEBUG, INFO, WARNING or ERROR message" <<std::endl;
	std::string input;
	std::getline(std::cin, input);
	std::string	message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	flag = -1;
	for (int i = 0; i < 4; i++)
	{
		if (input == message[i])
			flag = i;
	}
	if (flag == -1)
		std::cout << "Wrong input" << std::endl;
	else
		h.complain(input);
}