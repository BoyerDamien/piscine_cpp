/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:34:52 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/12 14:57:50 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>

/******************************************************************************
 *				Constructors
 *****************************************************************************/
Bureaucrat::Bureaucrat(std::string const &name,
					   int grade) throw(Bureaucrat::IGradeException)
	: _name(name), _grade(grade)
{
	if (grade < 1)
	{
		throw(Bureaucrat::GradeTooLowException());
	}
	else if (grade > 150)
	{
		throw(Bureaucrat::GradeTooHighException());
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
	: _name(other.getName()), _grade(other.getGrade())
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	(void)other;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

/******************************************************************************
 *				Exceptions
 *****************************************************************************/
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
/******************************************************************************
 *				Methods
 *****************************************************************************/
void Bureaucrat::intcrement()
{
	if (this->_grade > 1)
	{
		this->_grade--;
	}
}

void Bureaucrat::decrement()
{
	if (this->_grade < 150)
	{
		this->_grade++;
	}
}

/******************************************************************************
 *				Getters
 *****************************************************************************/
std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

/******************************************************************************
 *				Getters
 *****************************************************************************/
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	return os << b.getName() << " , bureaucrat grade " << b.getGrade();
}

bool operator==(Bureaucrat const &b1, Bureaucrat const &b2)
{
	return b1.getGrade() == b2.getGrade() && b1.getName() == b2.getName();
}
