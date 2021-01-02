/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:37:35 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 16:51:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sorcerer.hpp"
#include <iostream>
#include <sstream>

Sorcerer::Sorcerer(std::string name, std::string title)
	: _name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &other)
	: _name(other.getName()), _title(other.getTitle())
{

	std::cout << other.getName() << ", " << other.getTitle() << ", is born!"
			  << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title
			  << ", is dead. Consequences will never be the same" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &other)
{
	this->_name = other.getName();
	this->_title = other.getTitle();
	return *this;
}
/******************************************************************************
 *												Getters
 *****************************************************************************/

std::string Sorcerer::getName(void) const
{
	return this->_name;
}

std::string Sorcerer::getTitle(void) const
{
	return this->_title;
}

/******************************************************************************
 *												Methods
 *****************************************************************************/

std::string Sorcerer::introduce(void) const
{
	std::stringstream ss;
	ss << "I am " << this->_name << ", " << this->_title
	   << ", and I like ponies!" << std::endl;
	return ss.str();
}

void Sorcerer::polymorph(Victim const &vic) const
{
	vic.getPolymorphed();
}

/******************************************************************************
 *												Operator overloading
 *****************************************************************************/
std::ostream &operator<<(std::ostream &os, Sorcerer const &sorc)
{
	return os << sorc.introduce();
}
