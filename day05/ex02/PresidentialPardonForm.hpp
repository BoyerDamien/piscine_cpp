/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:56:35 by root              #+#    #+#             */
/*   Updated: 2021/01/14 11:33:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	PresidentialPardonForm(void); // Private default constructor

  public:
	PresidentialPardonForm(std::string const &) throw(AForm::IGradeException);
	PresidentialPardonForm(PresidentialPardonForm const &);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &);
	~PresidentialPardonForm(void);

	void doExec(Bureaucrat const &executor) const;
};

#endif
