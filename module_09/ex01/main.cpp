/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:41:46 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/30 17:00:34 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: This program should take";
		std::cout << " an inverted Polish mathematical expression as an argument." << std::endl;
		return (1);
	}
	std::string str = argv[1];
	RPN	rpn_performer;

	if (!rpn_performer.performRPN(str))
		return (1);
	return (0);
}