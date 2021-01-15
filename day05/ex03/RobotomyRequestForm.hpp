/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:33:47 by root              #+#    #+#             */
/*   Updated: 2021/01/15 11:23:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
  private:
	RobotomyRequestForm(void); // Private default constructor

  public:
	RobotomyRequestForm(std::string const &) throw(Form::IGradeException);
	RobotomyRequestForm(RobotomyRequestForm const &);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &);
	virtual ~RobotomyRequestForm(void);

	// Methods
	void doExec(Bureaucrat const &executor) const;
};

#endif
