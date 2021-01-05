/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:56:42 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/05 12:11:56 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include "./ISpaceMarine.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &other)
{
	(void)other;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &other)
{
	(void)other;
	return *this;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back ..." << std::endl;
}

/******************************************************************************
 *			Methods
 *****************************************************************************/

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. Purify it !" << std::endl;
}

ISpaceMarine *AssaultTerminator::clone() const
{
	return new AssaultTerminator();
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attaque with chainfists *" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}
