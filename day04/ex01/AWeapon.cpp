/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:29:05 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 15:47:40 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AWeapon.hpp"

/******************************************************************************
 *				Constructors
 *****************************************************************************/

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
	: _name(name), _apcost(apcost), _damage(damage)
{
	std::cout << "Weapon " << this->_name << " -- " << this->_apcost << " -- "
			  << this->_damage << " was created" << std::endl;
}

AWeapon::AWeapon(AWeapon const &other)
	: _name(other.getName()), _apcost(other.getAPCost()),
	  _damage(other.getDamage())
{
}

AWeapon &AWeapon::operator=(AWeapon const &other)
{
	this->_name = other.getName();
	this->_damage = other.getDamage();
	this->_apcost = other.getAPCost();
	return *this;
}

AWeapon::~AWeapon(void)
{
	std::cout << "Weapon " << this->_name << " -- " << this->_apcost << " -- "
			  << this->_damage << " was destroyed" << std::endl;
}

/******************************************************************************
 *				Getters
 *****************************************************************************/

std::string AWeapon::getName(void) const
{
	return this->_name;
}

int AWeapon::getAPCost(void) const
{
	return this->_apcost;
}

int AWeapon::getDamage(void) const
{
	return this->_damage;
}

/******************************************************************************
 *				Setters
 *****************************************************************************/

void AWeapon::setAPCost(int apcost)
{
	this->_apcost = apcost;
}

void AWeapon::setDamage(int damage)
{
	this->_damage = damage;
}

void AWeapon::setName(std::string name)
{
	this->_name = name;
}

bool operator==(AWeapon const &w1, AWeapon const &w2)
{
	return w1.getName() == w2.getName() && w1.getAPCost() == w2.getAPCost() &&
		   w1.getDamage() == w2.getDamage();
}
