/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:13 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/06 15:37:57 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGMENE_HPP
#define PMERGMENE_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <string>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	
	std::stack<int>	nums;

	bool	executeOperation(char token);
	bool	performPmergeMe(std::string str);
};

#endif