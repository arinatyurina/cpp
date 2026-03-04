/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:11 by atyurina          #+#    #+#             */
/*   Updated: 2026/03/04 21:21:35 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: numsVector(other.numsVector), numsDeque(other.numsDeque)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->numsVector = other.numsVector;
		this->numsDeque = other.numsDeque;
	}
	return (*this);
}

// helper comparator for C++98 (no lambdas)
static bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return a.second < b.second; // sort by the larger element in ascending order
}

std::vector<int> PmergeMe::executeOperationVector()
{
	// Step 1: Create pairs of elements
    std::vector< std::pair<int, int> > pairs;
    size_t i = 0;
	bool hasOddElement = (numsVector.size() % 2 != 0);
	int lastElement = 0;
	if (hasOddElement)
		lastElement = numsVector.back();
    while(i + 1 < numsVector.size())
    {
        int first = numsVector[i];
		int second = numsVector[i + 1];
        pairs.push_back(std::make_pair(first, second));
        i += 2;
    }
	
	// Step 2: Compare the elements in each pair and sort them
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		if (pairs[j].first > pairs[j].second)
			std::swap(pairs[j].first, pairs[j].second);
	}

	// Step 3: Sort the pairs based on the larger element of each pair
	std::sort(pairs.begin(), pairs.end(), comparePairs);

	// Step 4: Form 2 vectors: one for the larger elements (sorted) and one for the smaller elements
	std::vector<int> largerElements;
	std::vector<int> smallerElements;
	for (size_t k = 0; k < pairs.size(); ++k)
	{
		const std::pair<int,int> &p = pairs[k];
		largerElements.push_back(p.second);
		smallerElements.push_back(p.first);
	}
	// Step 5: Binary insertion sort the smaller elements into the sorted larger elements
	std::vector<int> sorting = largerElements; // Start with the sorted larger elements
	for (size_t m = 0; m < smallerElements.size(); ++m)
	{
		int small = smallerElements[m];
		int big   = largerElements[m];

		// Limit the search to the position of the big element
		auto bigPos = std::lower_bound(sorting.begin(), sorting.end(), big);
		auto insertPos = std::lower_bound(sorting.begin(), bigPos, small);

		sorting.insert(insertPos, small);
	}

	if (hasOddElement)
	{
		int lastElement = numsVector.back();
		auto pos = std::lower_bound(sorting.begin(), sorting.end(), lastElement);
		sorting.insert(pos, lastElement);
	}

	return (sorting);
}

bool PmergeMe::executeOperationDeque()
{
	// Implementation for deque operation
	return true;
}