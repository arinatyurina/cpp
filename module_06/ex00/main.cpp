/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:09:59 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/09 23:03:05 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "You need to pass one string as a parameter!" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	// ScalarConverter::convert("Hello!");
	// ScalarConverter::convert("35");
	// ScalarConverter::convert("32.21");
	// ScalarConverter::convert("42.21f");
}