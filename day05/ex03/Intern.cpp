/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 09:12:50 by root              #+#    #+#             */
/*   Updated: 2021/01/15 11:19:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

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
 *			Static functions
 *****************************************************************************/
static AForm *makeShrubbery(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makePardon(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

static AForm *makeRobotomy(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
AForm *Intern::makeAForm(std::string const &type, std::string const &target) const
{
	static std::string const TYPES[] = {
		"Robotomy request", "Presidential pardon", "Shrubbery creation"};
	static AForm *(*ACTIONS[])(std::string const &) = {makeRobotomy, makePardon,
													  makeShrubbery};
	for (int i = 0; i < 3; i++)
	{
		if (type == TYPES[i])
		{
			std::cout << "Intern creates " << type << std::endl;
			return ACTIONS[i](target);
		}
	}
	std::cerr << "AForm " << type << " unknown !" << std::endl;
	return NULL;
}
