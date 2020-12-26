/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:40 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:23:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include <cstdlib>
#include <iostream>

/******************************************************************************
 *			Constructors and destructor
 ******************************************************************************/
FragTrap::FragTrap(std::string name) : _name(name)
{
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap " << this->_name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	this->_name = other.getName() + " copy";
	this->_hitPoint = other.getHP();
	this->_maxEnergyPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = other.getEnergyPoint();
	this->_level = other.getLevel();
	this->_meleeAttack = 30;
	this->_rangedAttack = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

/****************************************************************************
 * 				Getters
 ****************************************************************************/
std::string FragTrap::getName(void) const
{
	return this->_name;
}

int FragTrap::getHP(void) const
{
	return this->_hitPoint;
}
int FragTrap::getLevel(void) const
{
	return this->_level;
}
int FragTrap::getEnergyPoint(void) const
{
	return this->_energyPoint;
}

/****************************************************************************
 *				specific attacks
 ****************************************************************************/
void FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	const char *attacks[] = {"lance flamme", "mimi-queue", "rugissement", "charge", "ultralaser"};
	int index = 0 + std::rand() % 5;
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint >= 25)
		{
			this->_energyPoint -= 25;
			std::cout << "FragTrap " << this->_name << " loose 25 points of energy, launch " << attacks[index]
					  << " and switch..." << std::endl;
		}
		else
		{
			std::cout << "FragTrap " << this->_name << " has not enough energy" << std::endl;
		}
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
	}
}
/****************************************************************************
 *				Basic Attacks
 ****************************************************************************/
void FragTrap::rangedAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout << "FragTrap " << this->_name << " attacks " << target << " with a rangedAttack and deals "
					  << this->_rangedAttack << " points of dammage and lose 1 point of energy and has now "
					  << this->_energyPoint << " of energy points" << std::endl;
		}
		else
		{
			std::cout << "FragTrap " << this->_name << " has no more energy and cannot attack" << std::endl;
		}
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
	}
}

void FragTrap::meleeAttack(const std::string &target)
{
	if (this->_hitPoint > 0)
	{
		if (this->_energyPoint > 0)
		{
			this->_energyPoint--;
			std::cout << "FragTrap " << this->_name << " attacks " << target << " with a meleeAttack and deals "
					  << this->_meleeAttack << " points of dammage and lose 1 point of energy and has now "
					  << this->_energyPoint << " of energy points" << std::endl;
		}
		else
		{
			std::cout << "FragTrap " << this->_name << " has no more energy and cannot attack" << std::endl;
		}
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount)
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
		std::cout << "FragTrap " << this->_name << " takes " << amount << " damages and has now " << this->_hitPoint
				  << " of HP" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	const int newHp = amount + this->_hitPoint;
	if (amount > this->_maxHitPoint)
	{
		this->_hitPoint = this->_maxHitPoint;
	}
	else
	{
		this->_hitPoint = newHp;
	}
	std::cout << "FragTrap " << this->_name << " has been repaired and has now " << this->_hitPoint << " of HP"
			  << std::endl;
}

std::ostream &operator<<(std::ostream &stream, FragTrap const &obj)
{
	stream << obj.getName();
	return stream;
}
