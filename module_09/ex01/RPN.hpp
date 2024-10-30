/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:41:51 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/30 17:00:56 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <string>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN& operator=(const RPN &other);
	
	std::stack<int>	nums;

	bool	executeOperation(char token);
	bool	performRPN(std::string str);
};

#endif

/*
Polish notation (PN), also known as normal Polish notation (NPN), Polish prefix notation or simply prefix notation,
is a mathematical notation in which operators precede their operands, in contrast to the more common infix notation,
in which operators are placed between operands, as well as reverse Polish notation (RPN), in which operators follow their operands. 
*/