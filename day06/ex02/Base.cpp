/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:23:44 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:26:06 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base(void)
{
	std::cout << "Base constructor" << std::endl;
}

Base::Base(Base const &other)
{
	(void)other;
}

Base &Base::operator=(const Base &other)
{
	(void)other;
	return *this;
}

Base::~Base()
{
	std::cout << "Base destructor" << std::endl;
}
