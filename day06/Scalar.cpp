/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:20:02 by root              #+#    #+#             */
/*   Updated: 2021/01/16 09:09:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <cctype>
#include <exception>
#include <iomanip>
#include <iostream>
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
	if (!std::isprint(result))
	{
		return ret + "Non displayable";
	}
	ret.push_back(result);
	return ret;
}

std::string Scalar::toInt() const
{
	if (this->_isNan() || this->_isString())
	{
		return "int: Impossible";
	}
	std::stringstream ss;
	ss << "int: " << static_cast<int>(this->_value);
	return ss.str();
}

std::string Scalar::toFloat() const
{
	if (this->_isString())
	{
		return "float: Impossible";
	}
	if (this->_isNan())
	{
		return "float: nanf";
	}
	std::stringstream ss;
	ss << "float: " << std::fixed << std::setprecision(1) << this->_value
	   << "f";
	return ss.str();
}

std::string Scalar::toDouble() const
{
	if (this->_isString())
	{
		return "double: Impossible";
	}
	if (this->_isNan())
	{
		return "double: nan";
	}
	std::stringstream ss;
	ss << "double: " << std::fixed << std::setprecision(1)
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
