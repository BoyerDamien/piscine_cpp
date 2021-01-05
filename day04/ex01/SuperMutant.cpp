/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:16:16 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 14:49:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"
#include "Enemy.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Break everything !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &other) : Enemy(other)
{
	std::cout << "Gaaah. Break everything !" << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &other)
{
	this->setHP(other.getHP());
	this->setType(other.getType());
	return *this;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
	if ((damage - 3) > 0 && this->getHP() > 0)
	{
		this->setHP(this->getHP() - (damage - 3));
	}
	if (this->getHP() <= 0)
	{
		this->~SuperMutant();
	}
}
