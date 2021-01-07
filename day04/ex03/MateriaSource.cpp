/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:26:29 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 12:30:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MateriaSource.hpp"
#include "AMateria.hpp"

/******************************************************************************
 *				Some static functions
 *****************************************************************************/
static AMateria **deepCopy(AMateria **_table)
{
	AMateria **ret = new AMateria *[4];
	for (int i = 0; i < 4; i++)
	{
		if (_table[i])
			ret[i] = _table[i]->clone();
		else
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
MateriaSource::MateriaSource(void) : _materias(initMaterias())
{
}

MateriaSource::MateriaSource(MateriaSource const &other)
	: _materias(deepCopy(other.getMaterias()))
{
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	this->_cleanMaterias();
	this->_materias = deepCopy(other.getMaterias());
	return *this;
}

MateriaSource::~MateriaSource()
{
	this->_cleanMaterias();
}

/******************************************************************************
 *				Getters
 *****************************************************************************/
AMateria **MateriaSource::getMaterias() const
{
	return this->_materias;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
AMateria *MateriaSource::createMateria(const std::string &type)
{
	AMateria *tmp = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			tmp = this->_materias[i];
		}
	}
	return tmp ? tmp->clone() : tmp;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = materia;
			return;
		}
	}
}

void MateriaSource::_cleanMaterias(void)
{
	if (this->_materias)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
		}
		delete[] this->_materias;
	}
}

bool operator==(MateriaSource const &m1, MateriaSource const &m2)
{
	AMateria **materias1 = m1.getMaterias();
	AMateria **materias2 = m2.getMaterias();

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
	return true;
}
