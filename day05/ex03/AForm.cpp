/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:25:52 by root              #+#    #+#             */
/*   Updated: 2021/01/14 11:43:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <exception>

/******************************************************************************
 *				Constructors
 *****************************************************************************/
AForm::AForm(std::string const &name, std::string const &target,
		   int const gradeToSign,
		   int const gradeToExec) throw(AForm::IGradeException)
	: _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign),
	  _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
	{
		throw(AForm::GradeTooLowException());
	}
	else if (gradeToSign > 150 || gradeToExec > 150)
	{
		throw(AForm::GradeTooHighException());
	}
}

AForm::AForm(AForm const &other)
	: _name(other.getName()), _target(other.getTarget()),
	  _isSigned(other.isSigned()), _gradeToSign(other.getGradeToSign()),
	  _gradeToExec(other.getGradeToExec())
{
}

AForm &AForm::operator=(AForm const &other)
{
	this->_target = other.getTarget();
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " destroyed" << std::endl;
}

/******************************************************************************
 *				Getters
 *****************************************************************************/
std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::isSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToExec() const
{
	return this->_gradeToExec;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

std::string AForm::getTarget() const
{
	return this->_target;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
void AForm::beSigned(Bureaucrat const &b) throw(AForm::IGradeException)
{
	if (b.getGrade() < this->_gradeToSign)
	{
		this->_isSigned = true;
	}
	else
	{
		throw(AForm::GradeTooLowException());
	}
}

void AForm::execute(Bureaucrat const &executor) const throw(std::exception)
{
	if (executor.getGrade() <= this->_gradeToExec)
	{
		if (this->_isSigned)
		{
			this->doExec(executor);
		}
		else
		{
			throw(AForm::IsNotSignedException());
		}
	}
	else
	{
		throw(AForm::GradeTooLowException());
	}
}

/******************************************************************************
 *				Exceptions
 *****************************************************************************/
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::IsNotSignedException::what() const throw()
{
	return "AForm not signed";
}

/******************************************************************************
 *			Operator overloading
 *****************************************************************************/
bool operator==(AForm const &f1, AForm const &f2)
{
	return f1.getGradeToExec() == f2.getGradeToExec() &&
		   f1.getGradeToSign() == f2.getGradeToSign() &&
		   f1.getName() == f2.getName();
}

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	return os << "Name: " << f.getName()
			  << " Grade to exec :" << f.getGradeToExec()
			  << " Grade to sign: " << f.getGradeToSign() << std::endl;
}
