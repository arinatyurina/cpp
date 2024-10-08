/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:09:59 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/08 23:11:54 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main()
{
	ScalarConverter::convert("Hello!");
	ScalarConverter::convert("42");
	ScalarConverter::convert("32.21");
	ScalarConverter::convert("42.21f");
}