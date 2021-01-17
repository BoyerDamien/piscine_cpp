/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:59:17 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/14 11:37:13 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

/******************************************************************************
 *			Constructors
 *****************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) throw(
	AForm::IGradeException)
	: AForm("Pardon", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const &other)
	: AForm(other)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &other)
{
	(void)other;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << this->getName() << " destroyed!"
			  << std::endl;
}

/******************************************************************************
 *			Methods
 *****************************************************************************/
void PresidentialPardonForm::doExec(const Bureaucrat &executor) const
{
	(void)executor;
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox"
			  << std::endl;
}
