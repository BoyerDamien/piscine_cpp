/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:25:52 by root              #+#    #+#             */
/*   Updated: 2021/01/14 11:43:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <exception>

/******************************************************************************
 *				Constructors
 *****************************************************************************/
Form::Form(std::string const &name, std::string const &target,
		   int const gradeToSign,
		   int const gradeToExec) throw(Form::IGradeException)
	: _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign),
	  _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
	{
		throw(Form::GradeTooLowException());
	}
	else if (gradeToSign > 150 || gradeToExec > 150)
	{
		throw(Form::GradeTooHighException());
	}
}

Form::Form(Form const &other)
	: _name(other.getName()), _target(other.getTarget()),
	  _isSigned(other.isSigned()), _gradeToSign(other.getGradeToSign()),
	  _gradeToExec(other.getGradeToExec())
{
}

Form &Form::operator=(Form const &other)
{
	this->_target = other.getTarget();
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

/******************************************************************************
 *				Getters
 *****************************************************************************/
std::string Form::getName() const
{
	return this->_name;
}

bool Form::isSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToExec() const
{
	return this->_gradeToExec;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

std::string Form::getTarget() const
{
	return this->_target;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
void Form::beSigned(Bureaucrat const &b) throw(Form::IGradeException)
{
	if (b.getGrade() < this->_gradeToSign)
	{
		this->_isSigned = true;
	}
	else
	{
		throw(Form::GradeTooLowException());
	}
}

void Form::execute(Bureaucrat const &executor) const throw(std::exception)
{
	if (executor.getGrade() <= this->_gradeToExec)
	{
		if (this->_isSigned)
		{
			this->doExec(executor);
		}
		else
		{
			throw(Form::IsNotSignedException());
		}
	}
	else
	{
		throw(Form::GradeTooLowException());
	}
}

/******************************************************************************
 *				Exceptions
 *****************************************************************************/
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::IsNotSignedException::what() const throw()
{
	return "Form not signed";
}

/******************************************************************************
 *			Operator overloading
 *****************************************************************************/
bool operator==(Form const &f1, Form const &f2)
{
	return f1.getGradeToExec() == f2.getGradeToExec() &&
		   f1.getGradeToSign() == f2.getGradeToSign() &&
		   f1.getName() == f2.getName();
}

std::ostream &operator<<(std::ostream &os, Form const &f)
{
	return os << "Name: " << f.getName()
			  << " Grade to exec :" << f.getGradeToExec()
			  << " Grade to sign: " << f.getGradeToSign() << std::endl;
}
