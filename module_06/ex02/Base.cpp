/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:40:52 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/28 17:03:06 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void SetColor(int textColor)
{
	std::cout << "\033[" << textColor << "m";
}

void ResetColor()
{
	std::cout << "\033[0m";
}

Base*	generate(void)
{
	srand(time(0)); //seed the random number generator (with the current time)
	Base	*baseptr;
	int	i = std::rand() % 3;
	std::cout << "i = " << i << "  i % 3 = " << (i % 3) << std::endl;
	SetColor(36);
	std:: cout << "Stage 1: generation\n";
	ResetColor();
	if (i == 0)
	{
		std::cout << "A has been generated" << std::endl;
		baseptr = new A;
	}
	else if (i == 1)
	{
		std::cout << "B has been generated" << std::endl;
		baseptr = new B;
	}
	else
	{
		std::cout << "C has been generated" << std::endl;
		baseptr = new C;
	}
	return (baseptr);
}

//A failed dynamic_cast returns nullptr, making it easy to check for success.
void	identify(Base *p)
{
	SetColor(36);
	std::cout << "Stage 2: identify(Base *p):\n";
	ResetColor();
	if (dynamic_cast <A*> (p))
		std::cout << "A has been identified" << std::endl;
	else if (dynamic_cast <B*> (p))
		std::cout << "B has been identified" << std::endl;
	else if (dynamic_cast <C*> (p))
		std::cout << "C has been identified" << std::endl;
}

// A failed dynamic_cast throws a std::bad_cast exception, which must be caught if failure is possible.
// std::bad_cast is an exception class in C++ that is thrown when a runtime type cast (specifically a dynamic_cast) fails.
void	identify(Base &p)
{
	SetColor(36);
	std::cout << "Stage 3: identify(Base &p)\n";
	ResetColor();
	try
	{
		A &a = dynamic_cast <A&> (p);
		std::cout << "A has been identified" << std::endl;
		(void)a;
	}
	catch (const std::exception){}
	try
	{
 		B &b = (dynamic_cast <B&> (p));
		std::cout << "B has been identified" << std::endl;
		(void)b;
	}
	catch (const std::exception){}
	try
	{
		C &c = (dynamic_cast <C&> (p));
		std::cout << "C has been identified" << std::endl;
		(void)c;
	}
	catch (const std::exception){}
}

/*
This again tries to take the pointer in ptr and safely cast it to a pointer of type Type*. 
But this cast is executed at runtime, not compile time. 
Because this is a run-time cast, it is useful especially when combined with polymorphic classes. 
In fact, in certain cases the classes must be polymorphic in order for the cast to be legal.
 
Casts can go in one of two directions: 
from base to derived (B2D) or from derived to base (D2B). 
It's simple enough to see how D2B casts would work at runtime. 
Either ptr was derived from Type or it wasn't. In the case of D2B dynamic_cast<>s, the rules are simple. 
You can try to cast anything to anything else, and if ptr was in fact derived from Type, you'll get a Type* pointer back from dynamic_cast. 
Otherwise, you'll get a NULL pointer.


 */