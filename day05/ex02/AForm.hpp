/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:15:37 by root              #+#    #+#             */
/*   Updated: 2021/01/14 11:43:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>

class Bureaucrat;

class AForm
{
  private:
	std::string const _name;
	std::string _target;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExec;

	AForm(); // Private default constructor

  public:
	AForm(std::string const &, std::string const &, int const,
		 int const) throw(AForm::IGradeException);
	AForm(AForm const &);
	AForm &operator=(AForm const &);
	~AForm();

	// Getters
	std::string getName() const;
	std::string getTarget() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	// Methods
	void beSigned(Bureaucrat const &) throw(AForm::IGradeException);
	void execute(Bureaucrat const &executor) const throw(std::exception);
	virtual void doExec(Bureaucrat const &executor) const = 0;

	// Nested exception
	class IGradeException : public std::exception
	{
	  public:
		virtual const char *what(void) const throw() = 0;
	};

	class GradeTooLowException : public IGradeException
	{
	  public:
		const char *what(void) const throw();
	};

	class GradeTooHighException : public IGradeException
	{
	  public:
		const char *what(void) const throw();
	};

	class IsNotSignedException : public std::exception
	{
	  public:
		const char *what(void) const throw();
	};
};

bool operator==(AForm const &, AForm const &);
std::ostream &operator<<(std::ostream &, AForm const &);

#endif
