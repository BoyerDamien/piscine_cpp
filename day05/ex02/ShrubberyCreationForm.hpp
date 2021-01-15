/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:31:42 by root              #+#    #+#             */
/*   Updated: 2021/01/14 11:32:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATION_H
#define SHRUBBERYCREATION_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
  private:
	ShrubberyCreationForm(void); // Private default constructor

  public:
	ShrubberyCreationForm(std::string const &) throw(AForm::IGradeException);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);
	~ShrubberyCreationForm(void);

	void doExec(Bureaucrat const &executor) const;
};

#endif
