/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:49:49 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 16:21:52 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PowerFist.hpp"
#include "AWeapon.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
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
