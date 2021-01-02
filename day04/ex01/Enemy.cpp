/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 19:14:39 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 19:36:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Enemy.hpp"

/******************************************************************************
 *				Constructors
 *****************************************************************************/
Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
}

Enemy::Enemy(Enemy const &other) : _hp(other.getHP()), _type(other.getType())
{
}

Enemy &Enemy::operator=(const Enemy &other)
{
	this->setHP(other.getHP());
	this->setType(other.getType());
	return *this;
}

Enemy::~Enemy(void)
{
	std::cout << "Enemy " << this->_type << " destroyed" << std::endl;
}

/******************************************************************************
 *				Getters
 *****************************************************************************/
int Enemy::getHP(void) const
{
	return this->_hp;
}

std::string Enemy::getType(void) const
{
	return this->_type;
}

/******************************************************************************
 *				Setters
 *****************************************************************************/
void Enemy::setHP(int hp)
{
	this->_hp = hp;
}

void Enemy::setType(const std::string &type)
{
	this->_type = type;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
void Enemy::takeDamage(int damage)
{
	if (damage > 0 && this->_hp > 0)
	{
		this->_hp = this->_hp - damage;
	}
}