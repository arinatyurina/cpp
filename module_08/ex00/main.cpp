/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:09:13 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/16 00:21:47 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::cout << "<--- Vector container --->" << std::endl;
	std::vector<int> vector;
	vector.push_back(5);
	vector.push_back(10);
	vector.push_back(15);
	vector.push_back(20);
	vector.push_back(25);
	vector.push_back(30);
	vector.push_back(35);
	
	try
	{
		easyfind(vector, 25);
		easyfind(vector, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "<--- List container --->" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(10);
	list.push_back(15);
	list.push_back(20);
	list.push_back(25);
	list.push_back(30);
	list.push_back(35);

	try 
	{
		easyfind(list, 25);
		easyfind(list, 50);
	} catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

/*
			Containers in C++ STL (Standard Template Library)
	A container is a holder object that stores a collection of other objects (its elements).
They are implemented as class templates, which allows great flexibility in the types supported as elements. 
	The container manages the storage space for its elements and provides member functions to access them,
either directly or through iterators (reference objects with similar properties to pointers). 

	Sequence containers
Sequence containers implement data structures that can be accessed sequentially.

array: Static contiguous array (class template)
vector: Dynamic contiguous array (class template)
deque: Double-ended queue (class template)
forward_list: Singly-linked list (class template)
list: Doubly-linked list (class template)

	Associative containers
Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity). 

Set: Collection of unique keys, sorted by keys 
(class template)
Map: Collection of key-value pairs, sorted by keys, keys are unique (class template).
multiset: Collection of keys, sorted by keys (class template)
multimap: Collection of key-value pairs, sorted by keys 
(class template)

	Unordered associative containers
Unordered associative containers implement unsorted (hashed) data structures 
that can be quickly searched (O(1) amortized, O(n) worst-case complexity). 

unordered_set: Collection of unique keys, hashed by keys. (class template)
unordered_map: Collection of key-value pairs, hashed by keys, keys are unique. (class template)
unordered_multiset: Collection of keys, hashed by keys (class template)
unordered_multimap: Collection of key-value pairs, hashed by keys (class template)

	Container adapters
Container adapters provide a different interface for sequential containers. 

stack: Adapts a container to provide stack (LIFO data structure) (class template).
queue: Adapts a container to provide queue (FIFO data structure) (class template).
priority_queue: Adapts a container to provide priority queue (class template). 
*/