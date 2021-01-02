/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:00:42 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 11:03:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./NinjaTrap.hpp"
#include <iostream>

/******************************************************************************
 *                              Constructors
 *****************************************************************************/
NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	this->_hitPoint = 60;
	this->_maxHitPoint = 60;
	this->_energyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_meleeAttack = 60;
	this->_rangedAttack = 5;
	this->_armorDamageReduction = 0;
	this->_name = "Default";
	std::cout << "NinjaTrap " << this->_name << " default contrustor called"
			  << std::endl;
}

NinjaTrap::NinjaTrap(const std::string name) : ClapTrap(name)
{
	this->_energyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_hitPoint = 60;
	this->_maxHitPoint = 60;
	this->_meleeAttack = 60;
	this->_rangedAttack = 5;
	this->_armorDamageReduction = 0;
	this->_level = 1;

	std::cout << "NinjaTrap " << this->_name << " contrustor called"
			  << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other) : ClapTrap(other)
{
	this->_maxEnergyPoint = 120;
	this->_maxHitPoint = 60;
	this->_meleeAttack = 60;
	this->_rangedAttack = 5;
	this->_armorDamageReduction = 0;

	std::cout << "NinjaTrap " << this->_name << " copy contrustor called"
			  << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap " << this->_name << " destructor called"
			  << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &other)
{
	this->_name = other.getName();
	this->_hitPoint = other.getHP();
	this->_maxEnergyPoint = 120;
	this->_maxHitPoint = 60;
	this->_energyPoint = other.getEnergyPoint();
	this->_level = other.getLevel();
	this->_meleeAttack = 60;
	this->_rangedAttack = 5;
	this->_armorDamageReduction = 0;
	std::cout << "NinjaTrap " << this->_name << " assignation operator called"
			  << std::endl;
	return *this;
}

/******************************************************************************
 *                              Specific methods
 *****************************************************************************/
void NinjaTrap::ninjaShoeBox(const ClapTrap &other) const
{
	std::cout << "NinjaTrap " << this->_name << " eats " << other.getName()
			  << std::endl;
}

void NinjaTrap::ninjaShoeBox(const NinjaTrap &other) const
{
	std::cout << "NinjaTrap " << this->_name << " fights with "
			  << other.getName() << std::endl;
}

void NinjaTrap::ninjaShoeBox(const ScavTrap &other) const
{
	std::cout << "NinjaTrap " << this->_name << " sings with "
			  << other.getName() << std::endl;
}

void NinjaTrap::ninjaShoeBox(const FragTrap &other) const
{
	std::cout << "NinjaTrap " << this->_name << " plays with "
			  << other.getName() << std::endl;
}

void NinjaTrap::meleeAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout
				<< "(NinjaTrap method) " << this->_name << " attacks " << target
				<< " with a meleeAttack and deals " << this->_meleeAttack
				<< " points of dammage and lose 1 point of energy and has now "
				<< this->_energyPoint << " of energy points" << std::endl;
		}
		else
		{
			std::cout << this->_name << " has no more energy and cannot attack"
					  << std::endl;
		}
	}
	else
	{
		std::cout << this->_name << " is dead" << std::endl;
	}
}
