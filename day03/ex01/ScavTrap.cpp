/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:40 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:41:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

/******************************************************************************
 *			Constructors and destructor
 ******************************************************************************/
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
	std::cout << "ScavTrap " << this->_name << " default constructor called"
			  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->_name = other.getName() + " copy";
	this->_hitPoint = other.getHP();
	this->_maxHitPoint = 100;
	this->_energyPoint = other.getEnergyPoint();
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

/****************************************************************************
 * 				Getters
 ****************************************************************************/
std::string ScavTrap::getName(void) const
{
	return this->_name;
}

int ScavTrap::getHP(void) const
{
	return this->_hitPoint;
}
int ScavTrap::getLevel(void) const
{
	return this->_level;
}
int ScavTrap::getEnergyPoint(void) const
{
	return this->_energyPoint;
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
