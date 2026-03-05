/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   PmergeMe.cpp									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: atyurina <atyurina@student.42london.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/06 15:36:11 by atyurina		  #+#	#+#			 */
/*   Updated: 2026/03/05 19:34:22 by atyurina		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include	"PmergeMe.hpp"

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
		std::vector<int>::iterator bigPos = std::lower_bound(sorting.begin(), sorting.end(), big);
		std::vector<int>::iterator insertPos = std::lower_bound(sorting.begin(), bigPos, small);

		sorting.insert(insertPos, small);
	}

	if (hasOddElement)
	{
		int lastElement = numsVector.back();
		std::vector<int>::iterator pos = std::lower_bound(sorting.begin(), sorting.end(), lastElement);
		sorting.insert(pos, lastElement);
	}

	return (sorting);
}

std::deque<int> PmergeMe::executeOperationDeque()
{
	// Step 1: Split the sequence into pairs
	// Each pair will contain two elements from the original input.
	// Later we will ensure that inside each pair:
	// first = smaller element, second = larger element.
	std::deque<std::pair<int,int> > pairs;

	size_t i = 0;
	bool hasOddElement = (numsDeque.size() % 2 != 0);
	int lastElement = 0;
	if (hasOddElement)
		lastElement = numsDeque.back();
	while (i + 1 < numsDeque.size())
	{
		int a = numsDeque[i];
		int b = numsDeque[i + 1];

		// Step 2: Ensure each pair is internally sorted
		// After this:
		// pair.first  = smaller element
		// pair.second = larger element
		if (a > b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
		i += 2;
	}

	// Step 3: Sort the pairs according to their larger element
	// This guarantees that the sequence of larger elements
	// will already be globally sorted.
	std::sort(pairs.begin(), pairs.end(), comparePairs);

	// Step 4: Split pairs into two sequences:
	// larger  -> sorted main chain
	// smaller -> elements that must be inserted later
	std::deque<int> larger;
	std::deque<int> smaller;

	for (size_t k = 0; k < pairs.size(); k++)
	{
		larger.push_back(pairs[k].second);
		smaller.push_back(pairs[k].first);
	}

	// Step 5: Start building the final sorted sequence
	// Initially it contains only the larger elements
	// which are already sorted due to step 3.
	std::deque<int> sorting = larger;

	// Step 6: Insert the smaller elements
	// Key Ford-Johnson idea:
	// each "small" element is guaranteed to be <= its paired "big".
	// Therefore we only search in the part BEFORE that big element.
	for (size_t m = 0; m < smaller.size(); m++)
	{
		int small = smaller[m];
		int big = larger[m];

		// Find where the big element currently sits in the sorted chain
		std::deque<int>::iterator bigPos =
			std::lower_bound(sorting.begin(), sorting.end(), big);

		// Perform binary search ONLY in the range [begin, bigPos)
		// because we know small <= big
		std::deque<int>::iterator insertPos =
			std::lower_bound(sorting.begin(), bigPos, small);

		// Insert the element into the correct sorted position
		sorting.insert(insertPos, small);
	}

	// Now the container "sorting" contains all numbers sorted
	return sorting;
		if (hasOddElement)
	{
		int lastElement = numsDeque.back();
		std::deque<int>::iterator pos = std::lower_bound(sorting.begin(), sorting.end(), lastElement);
		sorting.insert(pos, lastElement);
	}
}

/*
Because std::vector stores elements contiguously,
iterations and bulk moves have excellent cache locality and
minimal pointer indirection, so CPU accesses are much faster.
std::deque uses multiple memory blocks and extra indirection,
which hurts cache performance and makes element movement/traversal slower in practice.
*/