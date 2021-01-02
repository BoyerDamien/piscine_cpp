/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:40 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 11:43:49 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SuperTrap.hpp"
#include "./NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>
#include <iostream>

/******************************************************************************
 *			Constructors and destructor
 ******************************************************************************/
SuperTrap::SuperTrap(void) : ClapTrap()
{
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_meleeAttack = 60;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	this->_name = "Default";
	std::cout << "SuperTrap " << this->_name << " default constructor called"
			  << std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_meleeAttack = 60;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	this->_name = name;
	std::cout << "SuperTrap " << this->_name << " constructor called"
			  << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &other) : ClapTrap(other)
{

	this->_maxHitPoint = 100;
	this->_maxEnergyPoint = 120;
	this->_meleeAttack = 60;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	this->_name = other.getName();
	this->_hitPoint = other.getHP();
	std::cout << "SuperTrap " << this->_name << " copy constructor called"
			  << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap " << this->_name << " destructor called"
			  << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &other)
{
	this->_name = other.getName();
	this->_hitPoint = other.getHP();
	this->_maxEnergyPoint = 120;
	this->_maxHitPoint = 100;
	this->_energyPoint = other.getEnergyPoint();
	this->_level = other.getLevel();
	this->_meleeAttack = 60;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "SuperTrap " << this->_name << " assignation operator called"
			  << std::endl;
	return *this;
}
