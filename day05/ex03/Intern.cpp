/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 09:12:50 by root              #+#    #+#             */
/*   Updated: 2021/01/15 09:30:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/******************************************************************************
 *			Constructors
 *****************************************************************************/
Intern::Intern(void)
{
	std::cout << "Intern created !" << std::endl;
}

Intern::Intern(Intern const &other)
{
	(void)other;
	std::cout << "Inter copy constructor called !" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called !" << std::endl;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
Form *Intern::makeForm(std::string const &name, std::string const &target) const
{
}
