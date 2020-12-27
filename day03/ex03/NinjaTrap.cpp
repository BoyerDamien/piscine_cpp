/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:00:42 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 14:13:04 by dboyer           ###   ########.fr       */
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
	this->_armorDamageReduction = 5;
	this->_name = "Default";
	std::cout << "NinjaTrap " << this->_name << " default contrustor called"
			  << std::endl;
}

NinjaTrap::NinjaTrap(const std::string name) : ClapTrap(name)
{
	this->_hitPoint = 60;
	this->_maxHitPoint = 60;
	this->_energyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_meleeAttack = 60;
	this->_rangedAttack = 5;
	this->_armorDamageReduction = 5;

	std::cout << "NinjaTrap " << this->_name << " contrustor called"
			  << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other) : ClapTrap(other)
{
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
	this->_maxEnergyPoint = this->_maxEnergyPoint;
	this->_maxHitPoint = this->_maxHitPoint;
	this->_energyPoint = other.getEnergyPoint();
	this->_level = other.getLevel();
	this->_meleeAttack = this->_meleeAttack;
	this->_rangedAttack = this->_rangedAttack;
	this->_armorDamageReduction = this->_armorDamageReduction;
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
