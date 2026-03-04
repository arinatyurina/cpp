/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:13 by atyurina          #+#    #+#             */
/*   Updated: 2026/03/04 20:40:05 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGMENE_HPP
#define PMERGMENE_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <algorithm>
#include <limits>
#include <cstdlib>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	
	std::vector<int>	numsVector;
	std::deque<int>	numsDeque;

	std::vector<int>	executeOperationVector();
	bool	executeOperationDeque();
};

#endif