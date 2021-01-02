/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:00:15 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 19:12:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Victim.hpp"
#include <ostream>
#include <sstream>

/******************************************************************************
 *						Constructors
 *****************************************************************************/

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "A random victim called " << this->_name << " just appeared!"
			  << std::endl;
}

Victim::Victim(Victim const &other) : _name(other.getName())
{
	std::cout << "A random victim called " << this->_name << " just appeared!"
			  << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "The victim " << this->_name
			  << " died for no apparent reasons!" << std::endl;
}

Victim &Victim::operator=(const Victim &other)
{
	this->_name = other.getName();
	return *this;
}

/******************************************************************************
 *						Getters
 *****************************************************************************/

std::string Victim::getName(void) const
{
	return this->_name;
}

/******************************************************************************
 *						Setters
 *****************************************************************************/
void Victim::setName(std::string name)
{
	this->_name = name;
}

/******************************************************************************
 *						Methods
 *****************************************************************************/

std::string Victim::introduce(void) const
{
	std::stringstream ss;
	ss << "I'm " << this->_name << " and I like otters!" << std::endl;
	return ss.str();
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " was just polymorphed in a cute little sheep!"
			  << std::endl;
}

/******************************************************************************
 *						Operator overloading
 *****************************************************************************/
std::ostream &operator<<(std::ostream &os, Victim const &vic)
{
	return os << vic.introduce();
}
