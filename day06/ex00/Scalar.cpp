/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:20:02 by dboyer              #+#    #+# */
/*   Updated: 2021/01/23 15:26:49 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <cctype>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <ostream>
#include <sstream>

/******************************************************************************
 *			Static functions
 ******************************************************************************/
static bool isFloat(std::string const &str)
{
	float result;
	std::istringstream ss(str);
	ss >> std::noskipws >> result;
	return !ss.fail() &&
		   ((str[ss.tellg()] == 'f' && ss.rdbuf()->in_avail() == 1) ||
			ss.eof());
}

static float convertToFloat(std::string const &str)
{
	float result;
	std::istringstream ss(str);
	ss >> std::noskipws >> result;
	return result;
}

/******************************************************************************
 *				Constructors
 *****************************************************************************/
Scalar::Scalar(std::string const &input)
	: _input(input), _isfloat(isFloat(input)), _value(convertToFloat(input))
{
}

Scalar::Scalar(Scalar const &other) : _input(other.getInput())
{
}

Scalar &Scalar::operator=(const Scalar &other)
{
	(void)other;
	return *this;
}

Scalar::~Scalar()
{
}
/******************************************************************************
 *				Getters
 *****************************************************************************/
std::string Scalar::getInput(void) const
{
	return this->_input;
}

/******************************************************************************
 *				Checkers
 ******************************************************************************/
bool Scalar::_isNan(void) const
{
	return (this->_input == "nan" || this->_input == "nanf");
}

bool Scalar::_isString(void) const
{
	return (this->_input.length() > 1 && !this->_isfloat && !this->_isNan());
}

bool Scalar::_isInf(void) const
{
	return this->_input == "inf" || this->_input == "-inf" ||
		   this->_input == "-inff" || this->_input == "inff";
}

/******************************************************************************
 *			Methods
 *****************************************************************************/

std::string Scalar::toChar(void) const
{
	std::string ret = "char: ";
	if (this->_isString() || this->_value < 0)
	{
		return ret + "Impossible";
	}
	char result = static_cast<char>(this->_value);
	if (result > CHAR_MAX || result < CHAR_MIN)
	{
		return ret + "Impossible";
	}
	if (!std::isprint(result))
	{
		return ret + "Non displayable";
	}
	ret.push_back(result);
	return ret;
}

std::string Scalar::toInt() const
{
	std::string ret = "int: ";
	int casted = static_cast<int>(this->_value);

	if (this->_isInf())
	{
		return ret + "inf";
	}
	if (this->_isNan() || this->_isString() || casted >= INT_MAX ||
		casted <= INT_MIN)
	{
		return ret + "Impossible";
	}
	std::stringstream ss;
	ss << ret << casted;
	return ss.str();
}

std::string Scalar::toFloat() const
{
	std::string ret = "float: ";
	if (this->_isInf())
	{
		return this->_input[0] == '-' ? ret + "-inff" : ret + "inff";
	}
	if (this->_isString())
	{
		return ret + "Impossible";
	}
	if (this->_isNan())
	{
		return ret + "nanf";
	}
	std::stringstream ss;
	ss << ret << std::fixed << std::setprecision(1) << this->_value << "f";
	return ss.str();
}

std::string Scalar::toDouble() const
{
	std::string ret = "double: ";
	if (this->_isInf())
	{
		return this->_input[0] == '-' ? ret + "-inf" : ret + "inf";
	}
	if (this->_isString())
	{
		return ret + "Impossible";
	}
	if (this->_isNan())
	{
		return ret + "nan";
	}
	std::stringstream ss;
	ss << ret << std::fixed << std::setprecision(1)
	   << static_cast<double>(this->_value);
	return ss.str();
}

/******************************************************************************
 *			Operator overloading
 ******************************************************************************/
std::ostream &operator<<(std::ostream &os, Scalar const &s)
{
	return os << s.toChar() << std::endl
			  << s.toInt() << std::endl
			  << s.toFloat() << std::endl
			  << s.toDouble() << std::endl;
}
