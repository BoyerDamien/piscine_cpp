/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:23:44 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:27:38 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(void)
{
	std::cout << "C constructor" << std::endl;
}

C::C(C const &other)
{
	(void)other;
}

C &C::operator=(const C &other)
{
	(void)other;
	return *this;
}

C::~C()
{
	std::cout << "C destructor" << std::endl;
}
