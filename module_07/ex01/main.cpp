/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:21:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/14 20:56:13 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	IntIncreaseAndPrint(int n)
{
	std::cout << "number = " << n << "; increased number = " << n + 1 << std::endl;
}

void	CharToUpperAndPrint(char c)
{
	c = toupper(c);
	std::cout << c;
}

int	main()
{
	int arr[] = {0, 1, 2, 3, 4, 5};
	int	len = 6;

	iter(arr, len, IntIncreaseAndPrint);

	char arr2[] = {"Hello World"};
	int len2 = 11;

	iter(arr2, len2, CharToUpperAndPrint);
}