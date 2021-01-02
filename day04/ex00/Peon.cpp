/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:16:07 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 19:12:14 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Peon.hpp"
#include "Victim.hpp"

/******************************************************************************
 *				Constructors
 *****************************************************************************/

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog" << std::endl;
}

Peon &Peon::operator=(Peon const &other)
{
	this->setName(other.getName());
	return *this;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

/******************************************************************************
 *        Methods
 *****************************************************************************/

void Peon::getPolymorphed(void) const
{
	std::cout << this->getName() << " was just polymorphed into a pink pony!"
			  << std::endl;
}
