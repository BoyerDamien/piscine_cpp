/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:40 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/28 18:03:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

/******************************************************************************
 *			Constructors and destructor
 ******************************************************************************/
FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap " << this->_name << " default constructor called"
			  << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap " << this->_name << " constructor called"
			  << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->_maxHitPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap " << this->_name << " copy constructor called"
			  << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destructor called"
			  << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	this->_name = other.getName();
	this->_hitPoint = other.getHP();
	this->_maxHitPoint = 100;
	this->_energyPoint = other.getEnergyPoint();
	this->_maxEnergyPoint = 100;
	this->_level = other.getLevel();
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap " << this->_name << " assignation operator called"
			  << std::endl;
	return *this;
}
/****************************************************************************
 *				specific attacks
 ****************************************************************************/
void FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	const char *attacks[] = {"lance flamme", "mimi-queue", "rugissement",
							 "charge", "ultralaser"};
	int index = 0 + std::rand() % 5;
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint >= 25)
		{
			this->_energyPoint -= 25;
			std::cout << "FragTrap " << this->_name
					  << " loose 25 points of energy, launch " << attacks[index]
					  << " on " << target << " and switch..." << std::endl;
		}
		else
		{
			std::cout << "FragTrap " << this->_name << " has not enough energy"
					  << std::endl;
		}
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
	}
}
