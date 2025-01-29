/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:01:34 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/29 17:56:31 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	printIntArray(Array<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
		if (i != arr.size() - 1)
			std::cout << " - ";
	}
	std::cout << std::endl;
}

int	main()
{
	std::cout << BLUE << "Instantiate an array of 7 elements:\n" << RESET;
	Array<int>	arr(7);
	/*set int values from 0 to 6 and print them*/
	for (int i = 0; i < arr.size(); i++)
		arr[i] = i;
	printIntArray(arr);

	std::cout << YELLOW << "Testing size function:\n" << RESET;
	std::cout << "Size is " << arr.size() << std::endl;

	std::cout << YELLOW << "Testing operator[]:\n" << RESET;
	try
	{
		std::cout << "Output value arr[3] through operator[]: " << arr[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << YELLOW << "Testing operator[] with the index out of bounds:\n" << RESET;
	try
	{
		std::cout << "Output value arr[10] through operator[]: " << arr[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << BLUE << "Create Array2 with copy construtor:\n" << RESET;
	Array<int> arr2(arr);
	/*let's check values by outputting them*/
	printIntArray(arr2);

	std::cout << BLUE << "Create Array3:\n" << RESET;
	Array<int> arr3(3);
	printIntArray(arr3);
	std::cout << YELLOW << "Operator= usage:\n" << RESET;
	arr3 = arr2;
	printIntArray(arr3);
}