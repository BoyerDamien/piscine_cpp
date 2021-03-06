/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 08:59:30 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/15 08:49:59 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

/******************************************************************************
 *				Constructors
 *****************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) throw(
	AForm::IGradeException)
	: AForm("Shrubbery", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const &other)
{
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " destroyed !"
			  << std::endl;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/
void ShrubberyCreationForm::doExec(const Bureaucrat &executor) const
{
	(void)executor;
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (file.is_open())
	{
		file << "		          .     .  .      +     .      .          .\n\
     .       .      .     #       .           .\n\
        .      .         ###            .      .      .\n\
      .      .    #:. .:## ##:. .:#   .      .\n\
          .      .  #### ### ####   .\n\
       .      #:.    .:# ### #:.    .:#   .        .       .\n\
  .              ######### #########         .        .\n\
        .     #:.   #### ### ####   .:#    .       .\n\
     .     .   #######  ## ##  #######                   .\n\
                . ## ##### ##### ##            .      .\n\
    .    #:. ...  .:## ### ### ##:.  ... .:#      .\n\
      .      ####### ## ##### ## #######       .     .\n\
    .    .      #####  #######  #####     .      .\n\
            .            000           .     .\n\
       .         .   .   000     .        .       .\n\
.. .. ..................O000O........................ ......"
			 << std::endl;
		file.close();
	}
	else
	{
		std::cerr << "Error: " << fileName << " does not exist" << std::endl;
	}
}
