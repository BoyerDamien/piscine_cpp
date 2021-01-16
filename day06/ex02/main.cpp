/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:02:07 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:39:56 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>
#include <typeinfo>

void identify_from_pointer(Base *p)
{
	A *a;
	B *b;
	C *c;

	if ((a = dynamic_cast<A *>(p)))
	{
		std::cout << "A" << std::endl;
	}
	else if ((b = dynamic_cast<B *>(p)))
	{
		std::cout << "B" << std::endl;
	}
	else if ((c = dynamic_cast<C *>(p)))
	{
		std::cout << "C" << std::endl;
	}
}

void identify_from_reference(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
}

int main(void)
{
	A *a = new A;
	B *b = new B;
	C *c = new C;

	identify_from_pointer(a);
	identify_from_pointer(b);
	identify_from_pointer(c);

	identify_from_reference(*a);
	identify_from_reference(*b);
	identify_from_reference(*c);

	delete a;
	delete b;
	delete c;
	return 0;
}
