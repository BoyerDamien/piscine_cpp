/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:23:44 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:27:17 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(void)
{
	std::cout << "B constructor" << std::endl;
}

B::B(B const &other)
{
	(void)other;
}

B &B::operator=(const B &other)
{
	(void)other;
	return *this;
}

B::~B()
{
	std::cout << "B destructor" << std::endl;
}
