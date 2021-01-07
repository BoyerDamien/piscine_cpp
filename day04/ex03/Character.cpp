/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:41:26 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 12:54:22 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"
#include "ICharacter.hpp"

/******************************************************************************
 *				Some static functions
 *****************************************************************************/
static AMateria **deepCopy(AMateria **_table)
{
	AMateria **ret = new AMateria *[4];
	for (int i = 0; i < 4; i++)
	{
		ret[i] = _table[i];
	}
	return ret;
}

static AMateria **initMaterias(void)
{
	AMateria **ret = new AMateria *[4];
	for (int i = 0; i < 4; i++)
	{
		ret[i] = NULL;
	}
	return ret;
}

/******************************************************************************
 *				Constructors
 *****************************************************************************/
Character::Character(std::string const &name)
	: _name(name), _materias(initMaterias())
{
}

Character::Character(Character const &other)
	: _name(other.getName()), _materias(deepCopy(other.getMaterias()))
{
}

Character &Character::operator=(Character const &other)
{
	this->_name = other.getName();
	delete[] this->_materias;
	this->_materias = deepCopy(other.getMaterias());
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			delete this->_materias[i];
		}
	}
	delete[] this->_materias;
}

/******************************************************************************
 *				Getters
 *****************************************************************************/

AMateria **Character::getMaterias() const
{
	return this->_materias;
}

std::string const &Character::getName() const
{
	return this->_name;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
void Character::equip(AMateria *equip)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = equip;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && this->_materias[idx] != NULL)
	{
		this->_materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &character)
{
	if (idx < 4 && idx >= 0 && this->_materias[idx] != NULL)
	{
		this->_materias[idx]->use(character);
	}
}

bool operator==(const Character &c1, const Character &c2)
{
	AMateria **materias1 = c1.getMaterias();
	AMateria **materias2 = c2.getMaterias();

	for (int i = 0; i < 4; i++)
	{
		if ((!materias1[i] && materias2[i]) || (materias1[i] && !materias2[i]))
		{
			return false;
		}
		if (materias1[i] && materias2[i] &&
			(materias1[i]->getType() != materias2[i]->getType() ||
			 materias1[i]->getXP() != materias2[i]->getXP()))
		{
			return false;
		}
	}
	return c1.getName() == c2.getName();
}
