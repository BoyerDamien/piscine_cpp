/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:40:38 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 19:08:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PlasmaRifle.hpp"
#include "AWeapon.hpp"
#include <iostream>

/******************************************************************************
 *				Constructors
 *****************************************************************************/
PlasmaRifle::PlasmaRifle(std::string const &name, int apcost, int damage)
	: AWeapon(name, apcost, damage)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &other) : AWeapon(other)
{
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &other)
{
	this->setName(other.getName());
	this->setAPCost(other.getAPCost());
	this->setDamage(other.getDamage());
	return *this;
}

PlasmaRifle::~PlasmaRifle(void)
{
	std::cout << "PlasmaRifle destroyed" << std::endl;
}

/******************************************************************************
 *			Methods
 *****************************************************************************/

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
