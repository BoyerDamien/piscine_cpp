/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:23:44 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:26:51 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(void)
{
	std::cout << "A constructor" << std::endl;
}

A::A(A const &other)
{
	(void)other;
}

A &A::operator=(const A &other)
{
	(void)other;
	return *this;
}

A::~A()
{
	std::cout << "A destructor" << std::endl;
}
