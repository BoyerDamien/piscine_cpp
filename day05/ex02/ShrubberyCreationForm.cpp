/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 08:59:30 by root              #+#    #+#             */
/*   Updated: 2021/01/14 11:06:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

/******************************************************************************
 *				Constructors
 *****************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) throw(
	Form::IGradeException)
	: Form("Shruberry", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: Form(other)
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
void ShrubberyCreationForm::doExec(const Bureaucrat &executor)
{
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream file(fileName);
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
