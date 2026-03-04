/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:06 by atyurina          #+#    #+#             */
/*   Updated: 2026/03/04 20:58:47 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "PmergeMe.hpp"
#include    <ctime>
#include    <sstream>
#include    <cctype>

// int executePmergeMe(PmergeMe &pmergeMe)
// {
//     clock_t startVector = clock();
// 	pmergeMe.executeOperationVector();
// 	clock_t endVector = clock();
// 	double timeTakenVectorUs = static_cast<double>(endVector - startVector) * 1e6 / CLOCKS_PER_SEC;
// 	std::cout << "Time to process a range of " << pmergeMe.numsVector.size() << " elements with std::vector: " << timeTakenVectorUs << "us" << std::endl;

// 	clock_t startDeque = clock();
// 	if (!pmergeMe.executeOperationDeque())
// 	{
// 		std::cout << "Error: Failed to execute operation on deque." << std::endl;
// 		return (1);
// 	}
// 	clock_t endDeque = clock();
// 	double timeTakenDequeUs = static_cast<double>(endDeque - startDeque) * 1e6 / CLOCKS_PER_SEC;
// 	std::cout << "Time to process a range of " << pmergeMe.numsDeque.size() << " elements with std::deque: " << timeTakenDequeUs << "us" << std::endl;

//     return (0);
// }

int	main(int argc, char **argv)
{
	PmergeMe pmergeMe;
	std::set<int> seen;
	for (int i = 1; i < argc; ++i)
	{
		std::string s(argv[i]);
		if (s.empty())
		{
			std::cout << "Error: invalid argument: " << s << std::endl;
			return (1);
		}

		// check that all characters are digits
		for (size_t j = 0; j < s.size(); ++j)
		{
			if (!std::isdigit(static_cast<unsigned char>(s[j])))
			{
				std::cout << "Error: invalid argument: " << s << std::endl;
				return (1);
			}
		}

		// parse using C++98 stringstream
		std::istringstream iss(s);
		long val = 0;
		if (!(iss >> val) || !iss.eof())
		{
			std::cout << "Error: failed to parse: " << s << std::endl;
			return (1);
		}

		if (val <= 0 || val > std::numeric_limits<int>::max())
		{
			std::cout << "Error: number out of range: " << s << std::endl;
			return (1);
		}

		int num = static_cast<int>(val);
		if (seen.find(num) != seen.end())
		{
			std::cout << "Error: duplicate number: " << num << std::endl;
			return (1);
		}
		seen.insert(num);
		pmergeMe.numsVector.push_back(num);
		//pmergeMe.numsDeque.push_back(num);
	}

	if (pmergeMe.numsVector.size() < 2)
	{
		std::cout << "Error: This program should take at least 2 positive integers as arguments." << std::endl;
		return (1);
	}

	//output unsorted vector
	std::cout << "Unsorted vector: ";
	for (size_t i = 0; i < pmergeMe.numsVector.size(); ++i)
	{
		std::cout << pmergeMe.numsVector[i] << " ";
	}
	std::cout << std::endl;

	std::vector<int> sortedVector = pmergeMe.executeOperationVector();
	// output sorted vector
	std::cout << "Sorted vector: ";
	for (size_t i = 0; i < sortedVector.size(); ++i)
	{
		std::cout << sortedVector[i] << " ";
	}
	std::cout << std::endl;

	return (0);
}