/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:15:37 by root              #+#    #+#             */
/*   Updated: 2021/01/12 15:54:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

class Bureaucrat;

class Form
{
  private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExec;

	Form(); // Private default constructor

  public:
	Form(std::string const &, int const,
		 int const) throw(Form::IGradeException);
	Form(Form const &);
	Form &operator=(Form const &);
	~Form();

	// Getters
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	// Methods
	void beSigned(Bureaucrat const &) throw(Form::IGradeException);

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
};

bool operator==(Form const &, Form const &);
std::ostream &operator<<(std::ostream &, Form const &);

#endif
