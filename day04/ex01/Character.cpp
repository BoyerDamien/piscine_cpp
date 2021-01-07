/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:50:15 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 09:39:19 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"
#include "AWeapon.hpp"
#include <sstream>

Character::Character(std::string const &name)
	: _name(name), _weapon(NULL), _AP(40)
{
}

Character::Character(Character const &other)
	: _name(other.getName()), _weapon(other.getWeapon()), _AP(other.getAP())
{
}

Character &Character::operator=(const Character &other)
{
	this->_name = other.getName();
	this->_AP = other.getAP();
	this->_weapon = other.getWeapon();
	return *this;
}

Character::~Character(void)
{
	if (this->_weapon)
	{
		delete this->_weapon;
	}
}

/******************************************************************************
 *				Getters
 *****************************************************************************/

int Character::getAP(void) const
{
	return this->_AP;
}

std::string Character::getName(void) const
{
	return this->_name;
}

AWeapon *Character::getWeapon(void) const
{
	return this->_weapon;
}

/******************************************************************************
 *				Getters
 *****************************************************************************/
void Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void Character::attack(Enemy *enemy)
{
	if (this->_weapon && this->_AP >= this->_weapon->getAPCost())
	{
		std::cout << this->_name << "attack " << enemy->getType() << " with a "
				  << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		enemy->takeDamage(this->_weapon->getDamage());
		this->_AP -= this->_weapon->getAPCost();
	}
}

void Character::recoveryAP(void)
{
	this->_AP += 10;
	if (this->_AP > 40)
		this->_AP = 40;
}
/******************************************************************************
 *				Operator overloading
 *****************************************************************************/

std::ostream &operator<<(std::ostream &os, Character const &character)
{

	os << character.getName() << " has " << character.getAP();
	if (character.getWeapon())
		os << " AP and carries a " << character.getWeapon()->getName();
	else
		os << " AP and is unarmed";
	return os << std::endl;
}

bool operator==(Character const &c1, Character const &c2)
{
	return c1.getAP() == c2.getAP() && c1.getName() == c2.getName() &&
		   c1.getWeapon() == c2.getWeapon();
}
