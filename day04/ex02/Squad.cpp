/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:45:10 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 11:07:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Squad.hpp"
#include "ISpaceMarine.hpp"

static ISpaceMarine **deepCopy(ISpaceMarine **_table, int count)
{
	ISpaceMarine **ret = new ISpaceMarine *[count];
	for (int i = 0; i < count; i++)
	{
		ret[i] = _table[i]->clone();
	}
	return ret;
}

Squad::Squad(void) : _n(0), _content(NULL)
{
}

Squad::Squad(Squad const &other)
	: _n(other.getCount()),
	  _content(deepCopy(other.getContent(), other.getCount()))
{
}

Squad &Squad::operator=(Squad const &other)
{
	this->_cleanSquad();
	this->_n = other.getCount();
	this->_content = deepCopy(other.getContent(), this->_n);
	return *this;
}

Squad::~Squad()
{
	this->_cleanSquad();
}

/******************************************************************************
 *			Getters
 *****************************************************************************/
int Squad::getCount(void) const
{
	return this->_n;
}

ISpaceMarine *Squad::getUnit(int unit) const
{
	if (this->_content && unit >= 0 && unit < this->_n)
	{
		return this->_content[unit];
	}
	return NULL;
}

ISpaceMarine **Squad::getContent(void) const
{
	return this->_content;
}

/******************************************************************************
 *			Methods
 *****************************************************************************/

static bool isExists(ISpaceMarine **content, ISpaceMarine *marine, int n)
{
	if (content)
	{
		for (int i = 0; i < n; i++)
		{
			if (content[i] == marine)
			{
				return 1;
			}
		}
	}
	return 0;
}

void Squad::_cleanSquad(void)
{
	if (this->_content && this->_n > 0)
	{
		for (int i = 0; i < this->_n; i++)
		{
			delete this->_content[i];
		}
		delete[] this->_content;
		this->_content = NULL;
		this->_n = 0;
	}
}

int Squad::push(ISpaceMarine *marine)
{
	if (marine && !isExists(this->_content, marine, this->_n))
	{
		ISpaceMarine **tmp = this->_content;
		this->_content = new ISpaceMarine *[this->_n + 1];

		for (int i = 0; i < this->_n; i++)
		{
			this->_content[i] = tmp[i];
		}

		delete[] tmp;
		this->_content[this->_n] = marine;
		this->_n++;

		return 1;
	}
	return 0;
}

/******************************************************************************
 *			Operator overloading
 *****************************************************************************/

std::ostream &operator<<(std::ostream &os, ISquad const *squad)
{
	os << "[";
	for (int i = 0; i < squad->getCount(); i++)
	{
		os << " Marine" << i;
	}
	os << " ]";
	return os;
}
