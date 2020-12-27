/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:40 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 14:02:52 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

/******************************************************************************
 *			Constructors and destructor
 ******************************************************************************/
ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name = "Default";
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 50;
	this->_maxEnergyPoint = 50;
	this->_level = 1;
	this->_meleeAttack = 20;
	this->_rangedAttack = 15;
	this->_armorDamageReduction = 3;

	std::cout << "ScavTrap " << this->_name << " default constructor called"
			  << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = "Default";
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 50;
	this->_maxEnergyPoint = 50;
	this->_level = 1;
	this->_meleeAttack = 20;
	this->_rangedAttack = 15;
	this->_armorDamageReduction = 3;

	std::cout << "ScavTrap " << this->_name << " constructor called"
			  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->_name << " copy constructor called"
			  << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destructor called"
			  << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	this->_name = other.getName();
	this->_hitPoint = other.getHP();
	this->_maxEnergyPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = other.getEnergyPoint();
	this->_level = other.getLevel();
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "ScavTrap " << this->_name << " assignation operator called"
			  << std::endl;
	return *this;
}
/****************************************************************************
 *				specific attacks
 ****************************************************************************/
void ScavTrap::challengeNewcomer() const
{
	const char *challenges[] = {"ice bucket challenge",
								"chicken bucket challenge",
								"fingers bucket challenge"};
	int index = 0 + std::rand() % 5;
	if (this->_hitPoint > 0)
	{
		std::cout << "ScavTrap " << this->_name << " launch the "
				  << challenges[index] << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
	}
}
