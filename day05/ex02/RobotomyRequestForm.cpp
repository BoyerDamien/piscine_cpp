/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:37:12 by root              #+#    #+#             */
/*   Updated: 2021/01/14 11:07:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

/******************************************************************************
 *			Constructors
 *****************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) throw(
	Form::IGradeException)
	: Form("Robotomy", target, 72, 45)
{
	std::srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: Form(other)
{
	std::srand(time(NULL));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	RobotomyRequestForm const &other)
{
	std::srand(time(NULL));
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->getName() << " destroyed !"
			  << std::endl;
}

/******************************************************************************
 *			Methods
 *****************************************************************************/

void RobotomyRequestForm::doExec(Bureaucrat const &executor)
{
	if (std::rand() % 2)
	{
		std::cout << "Bruit de perceuse... " << this->getTarget()
				  << " has been robotomized" << std::endl;
	}
	else
	{
		std::cerr << "Robotomization failed !" << std::endl;
	}
}
