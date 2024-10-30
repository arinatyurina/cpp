/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:41:49 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/30 17:02:45 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	this->nums = other.nums;
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->nums = other.nums;
	}
	return (*this);
}

bool	RPN::executeOperation(char token)
{
	int num1;
	int	num2;

	if (nums.size() < 2)
	{
		std::cout << "Error: Not enought operands to perform operation" << std::endl;
		return (false);
	}
	num1 = nums.top();
	nums.pop();
	num2 = nums.top();
	nums.pop();

	if (token == '+')
		nums.push(num1 + num2);
	else if (token == '-')
		nums.push(num2 - num1);
	else if (token == '*')
		nums.push(num2 * num1);
	else if (token == '/')
	{
		if (num1 == 0)
		{
			std::cout << "Error: Can not perfort division by 0" << std::endl;
			return (false);
		}
		nums.push(num2 / num1);
	}
	else
	{
		std::cout << "Error: Wrong operation token" << std::endl;
		return (false);
	}
	return (true);
}

bool	RPN::performRPN(std::string str)
{
	int size = str.size();
	
	for (int i = 0; i < size; i++)
	{
		while (i < size && str[i] == ' ')
			i++;
		if (!(i < size))
			break;
		int	num = str[i];
		if (str[i] >= '0' && str[i] <= '9')
			nums.push(num - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (!executeOperation(str[i]))
				return (false);
		}
		else
		{
			std::cout << "Error: Undefined charter: " << str[i] << std::endl;
			return (false);
		}
	}
	std::cout << nums.top() << std::endl;
	return (true);
}