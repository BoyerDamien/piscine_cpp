/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:25:52 by root              #+#    #+#             */
/*   Updated: 2021/01/12 15:49:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/******************************************************************************
 *				Constructors
 *****************************************************************************/
Form::Form(std::string const &name, int const gradeToSign,
		   int const gradeToExec) throw(Form::IGradeException)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign),
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
	: _name(other.getName()), _isSigned(other.isSigned()),
	  _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
}

Form &Form::operator=(Form const &other)
{
	(void)other;
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
