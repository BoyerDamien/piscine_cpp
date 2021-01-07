/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:35:31 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 10:13:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : _xp(0), _type(type)
{
}

AMateria::AMateria(AMateria const &other)
	: _xp(other.getXP()), _type(other.getType())
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
	this->_xp = other.getXP();
	return *this;
}
/******************************************************************************
 *				Getters
 *****************************************************************************/
std::string const &AMateria::getType() const
{
	return this->_type;
}

int AMateria::getXP() const
{
	return this->_xp;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	this->_xp += 10;
}
