/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:40 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 12:14:36 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

/******************************************************************************
 *			Constructors and destructor
 ******************************************************************************/
ScavTrap::ScavTrap(void)
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

ScavTrap::ScavTrap(std::string name) : _name(name)
{
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

ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->_name = other.getName();
	this->_hitPoint = other.getHP();
	this->_maxHitPoint = 100;
	this->_energyPoint = other.getEnergyPoint();
	this->_maxEnergyPoint = 50;
	this->_level = other.getLevel();
	this->_meleeAttack = 20;
	this->_rangedAttack = 15;
	this->_armorDamageReduction = 3;
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
/******************************************************************************
 *			                    Getters
 ******************************************************************************/

std::string ScavTrap::getName() const
{
	return this->_name;
}

int ScavTrap::getHP(void) const
{
	return this->_hitPoint;
}

int ScavTrap::getMaxHP(void) const
{
	return this->_maxHitPoint;
}

int ScavTrap::getEnergyPoint(void) const
{
	return this->_energyPoint;
}

int ScavTrap::getMaxEnergyPoint(void) const
{
	return this->_maxEnergyPoint;
}

int ScavTrap::getLevel(void) const
{
	return this->_level;
}

int ScavTrap::getMeleeAttack(void) const
{
	return this->_meleeAttack;
}

int ScavTrap::getArmorDamageReduction(void) const
{
	return this->_armorDamageReduction;
}

int ScavTrap::getRangedAttack(void) const
{
	return this->_rangedAttack;
}

/****************************************************************************
 *				specific attacks
 ****************************************************************************/
void ScavTrap::challengeNewcomer() const
{
	std::string challenges[] = {"ice bucket challenge",
								"chicken bucket challenge",
								"fingers bucket challenge"};
	int index = 0 + std::rand() % 3;
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
/****************************************************************************
 *				Basic Attacks
 ****************************************************************************/
void ScavTrap::rangedAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout
				<< "ScavTrap " << this->_name << " attacks " << target
				<< " with a rangedAttack and deals " << this->_rangedAttack
				<< " points of dammage and lose 1 point of energy and has now "
				<< this->_energyPoint << " of energy points" << std::endl;
		}
		else
		{
			std::cout << "ScavTrap " << this->_name
					  << " has no more energy and cannot attack" << std::endl;
		}
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
	}
}

void ScavTrap::meleeAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout
				<< "ScavTrap " << this->_name << " attacks " << target
				<< " with a meleeAttack and deals " << this->_meleeAttack
				<< " points of dammage and lose 1 point of energy and has now "
				<< this->_energyPoint << " of energy points" << std::endl;
		}
		else
		{
			std::cout << "ScavTrap " << this->_name
					  << " has no more energy and cannot attack" << std::endl;
		}
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
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
		std::cout << "ScavTrap " << this->_name << " takes " << amount
				  << " damages and has now " << this->_hitPoint << " of HP"
				  << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
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
	std::cout << "ScavTrap " << this->_name << " has been repaired and has now "
			  << this->_hitPoint << " of HP" << std::endl;
}

/******************************************************************************
 *                      Operator overloading
 *****************************************************************************/

bool operator==(const ScavTrap &object1, const ScavTrap &object2)
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
