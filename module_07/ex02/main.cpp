/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:01:34 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/15 18:45:26 by atyurina         ###   ########.fr       */
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
	/*Instantiate an array of 7 elements*/
	Array<int>	arr(7);
	/*set int values from 0 to 6 and print them*/
	for (int i = 0; i < arr.size(); i++)
		arr[i] = i;
	printIntArray(arr);

	/*testing size function:*/
	std::cout << "Size is " << arr.size() << std::endl;

	/*testing operator[]*/
	try
	{
		std::cout << "Output value arr[3] through operator[]: " << arr[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
/*testing operator[] with the index out of bounds*/
	try
	{
		std::cout << "Output value arr[10] through operator[]: " << arr[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	/*Create Array2 with copy construtor*/
	Array<int> arr2(arr);
	/*let's check values by outputting them*/
	printIntArray(arr2);

	/*Create Array3*/
	Array<int> arr3(3);
	printIntArray(arr3);
	/*Operator= usage*/
	arr3 = arr2;
	printIntArray(arr3);
}