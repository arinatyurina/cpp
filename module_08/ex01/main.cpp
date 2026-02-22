/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:08:30 by atyurina          #+#    #+#             */
/*   Updated: 2026/01/24 17:14:59 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	//Test: Any attempt to add a new element 
	//if there are already N elements stored should throw an exception.
	try
	{
		sp.addNumber(20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//Adding multiple numbers to Span in a single call
	Span sp2 = Span(5);
	//Creating vector with numbers
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(100);
	vec.push_back(150);
	vec.push_back(500);
	//that's to test an exception by adding more numbers to vector than Span can hold
	//vec.push_back(1000); 

	//Adding all vector numbers to our Span in one call
	try
	{
		sp2.addNumber(vec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Span sp3 = Span(10042);
	for (int i = 0; i < 1042; i++)
	{
		sp3.addNumber(i);
	}
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;


	return (0);
}