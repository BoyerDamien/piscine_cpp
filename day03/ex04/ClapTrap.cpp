/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:40 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/28 18:55:16 by dboyer           ###   ########.fr       */
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
	std::cout << "ClapTrap " << this->_name << " default constructor called"
			  << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "ClapTrap " << this->_name << " constructor called"
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other.getName();
	this->_name = other.getName();
	this->_hitPoint = other.getHP();
	this->_energyPoint = other.getEnergyPoint();
	this->_level = other.getLevel();

	std::cout << "ClapTrap " << this->_name << " copy constructor called"
			  << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destructor called"
			  << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other.getName();
	this->_name = other.getName();
	this->_hitPoint = other.getHP();
	this->_energyPoint = other.getEnergyPoint();
	this->_level = other.getLevel();

	std::cout << "ClapTrap " << this->_name << " assignation operator called"
			  << std::endl;

	return *this;
}

/******************************************************************************
 *			                    Getters
 ******************************************************************************/

std::string ClapTrap::getName() const
{
	return this->_name;
}

int ClapTrap::getHP(void) const
{
	return this->_hitPoint;
}

int ClapTrap::getMaxHP(void) const
{
	return this->_maxHitPoint;
}

int ClapTrap::getEnergyPoint(void) const
{
	return this->_energyPoint;
}

int ClapTrap::getMaxEnergyPoint(void) const
{
	return this->_maxEnergyPoint;
}

int ClapTrap::getLevel(void) const
{
	return this->_level;
}

int ClapTrap::getMeleeAttack(void) const
{
	return this->_meleeAttack;
}

int ClapTrap::getArmorDamageReduction(void) const
{
	return this->_armorDamageReduction;
}

int ClapTrap::getRangedAttack(void) const
{
	return this->_rangedAttack;
}

/****************************************************************************
 *			                    Methods
 ****************************************************************************/
void ClapTrap::rangedAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout
				<< this->_name << " attacks " << target
				<< " with a rangedAttack and deals " << this->_rangedAttack
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

void ClapTrap::meleeAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout
				<< this->_name << " attacks " << target
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
		std::cout << this->_name << " takes " << amount
				  << " damages and has now " << this->_hitPoint << " of HP"
				  << std::endl;
	}
	else
	{
		std::cout << this->_name << " is dead" << std::endl;
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
	std::cout << this->_name << " has been repaired and has now "
			  << this->_hitPoint << " of HP" << std::endl;
}

/******************************************************************************
 *                      Operator overloading
 *****************************************************************************/

bool operator==(const ClapTrap &object1, const ClapTrap &object2)
{
	if (object1.getName() != object2.getName())
	{
		return false;
	}
	if (object1.getHP() != object2.getHP())
	{
		return false;
	}
	if (object1.getMaxHP() != object2.getHP())
	{
		return false;
	}
	if (object1.getEnergyPoint() != object2.getEnergyPoint())
	{
		return false;
	}
	if (object1.getMaxEnergyPoint() != object2.getMaxEnergyPoint())
	{
		return false;
	}
	if (object1.getLevel() != object2.getLevel())
	{
		return false;
	}
	if (object1.getMeleeAttack() != object2.getMeleeAttack())
	{
		return false;
	}
	if (object1.getRangedAttack() != object2.getRangedAttack())
	{
		return false;
	}
	if (object1.getArmorDamageReduction() != object2.getArmorDamageReduction())
	{
		return false;
	}
	return true;
}
