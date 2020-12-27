/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:40 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 12:31:11 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

/******************************************************************************
 *			Constructors and destructor
 ******************************************************************************/
ClapTrap::ClapTrap(void)
{
	this->_name = "Default";
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "ClapTrap " << this->_name << " default constructor called"
			  << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "ClapTrap " << this->_name << " constructor called"
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
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
	std::cout << "ClapTrap " << this->_name << " copy constructor called"
			  << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destructor called"
			  << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
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
	std::cout << "ClapTrap " << this->_name << " assignation operator called"
			  << std::endl;
	return *this;
}
/****************************************************************************
 * 				Getters
 ****************************************************************************/
std::string ClapTrap::getName(void) const
{
	return this->_name;
}

int ClapTrap::getHP(void) const
{
	return this->_hitPoint;
}
int ClapTrap::getLevel(void) const
{
	return this->_level;
}
int ClapTrap::getEnergyPoint(void) const
{
	return this->_energyPoint;
}

/****************************************************************************
 *				Basic Attacks
 ****************************************************************************/
void ClapTrap::rangedAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout
				<< "ClapTrap " << this->_name << " attacks " << target
				<< " with a rangedAttack and deals " << this->_rangedAttack
				<< " points of dammage and lose 1 point of energy and has now "
				<< this->_energyPoint << " of energy points" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->_name
					  << " has no more energy and cannot attack" << std::endl;
		}
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
}

void ClapTrap::meleeAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout
				<< "ClapTrap " << this->_name << " attacks " << target
				<< " with a meleeAttack and deals " << this->_meleeAttack
				<< " points of dammage and lose 1 point of energy and has now "
				<< this->_energyPoint << " of energy points" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->_name
					  << " has no more energy and cannot attack" << std::endl;
		}
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint > 0)
	{
		const int realDamage = amount - this->_armorDamageReduction;
		if (realDamage > 0 && realDamage < this->_hitPoint)
		{
			this->_hitPoint -= realDamage;
		}
		else if (realDamage > 0 && realDamage >= this->_hitPoint)
		{
			this->_hitPoint = 0;
		}
		std::cout << "ClapTrap " << this->_name << " takes " << amount
				  << " damages and has now " << this->_hitPoint << " of HP"
				  << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	const int newHp = amount + this->_hitPoint;
	if ((int)amount > this->_maxHitPoint)
	{
		this->_hitPoint = this->_maxHitPoint;
	}
	else
	{
		this->_hitPoint = newHp;
	}
	std::cout << "ClapTrap " << this->_name << " has been repaired and has now "
			  << this->_hitPoint << " of HP" << std::endl;
}
