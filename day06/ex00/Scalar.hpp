/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:01:32 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/15 19:03:38 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_H
#define SCALAR_H

#include <exception>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

class Scalar
{
  private:
	std::string _input;
	bool _isfloat;
	float _value;
	Scalar(void); // Private default constructor

  public:
	Scalar(std::string const &);
	Scalar(Scalar const &);
	Scalar &operator=(Scalar const &);
	~Scalar(void);

	// Methods
	std::string toChar(void) const;
	std::string toInt(void) const;
	std::string toFloat(void) const;
	std::string toDouble(void) const;

	// Checkers
	bool _isNan(void) const;
	bool _isString(void) const;

	// Getters
	std::string getInput(void) const;
};

std::ostream &operator<<(std::ostream &os, Scalar const &s);

#endif
