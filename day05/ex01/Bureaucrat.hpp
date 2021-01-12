/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:24:21 by root              #+#    #+#             */
/*   Updated: 2021/01/12 15:48:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>

class Form;

class Bureaucrat
{
  private:
	std::string const _name;
	int _grade;
	Bureaucrat(void); // Private default constructor

  public:
	// Constructor
	Bureaucrat(std::string const &, int) throw(Bureaucrat::IGradeException);
	Bureaucrat(Bureaucrat const &);
	Bureaucrat &operator=(Bureaucrat const &);
	~Bureaucrat(void);

	// Getters
	std::string getName(void) const;
	int getGrade(void) const;

	// Methods
	void intcrement(void);
	void decrement(void);
	void signForm(Form &);

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

std::ostream &operator<<(std::ostream const &, Bureaucrat const &);
bool operator==(Bureaucrat const &, Bureaucrat const &);

#endif
