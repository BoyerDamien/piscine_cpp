/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:49:49 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 19:09:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PowerFist.hpp"
#include "AWeapon.hpp"

PowerFist::PowerFist(std::string const &name, int apcost, int damage)
	: AWeapon(name, apcost, damage)
{
}

PowerFist::PowerFist(PowerFist const &other) : AWeapon(other)
{
}

PowerFist &PowerFist::operator=(const PowerFist &other)
{
	this->setName(other.getName());
	this->setAPCost(other.getAPCost());
	this->setDamage(other.getDamage());
	return *this;
}

PowerFist::~PowerFist(void)
{
	std::cout << "PowerFist destroyed" << std::endl;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM ! *" << std::endl;
}
