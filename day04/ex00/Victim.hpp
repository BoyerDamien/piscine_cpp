/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:50:03 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 19:11:51 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <ostream>

class Victim
{
  private:
	Victim(void); // Private default constructor
	std::string _name;

  public:
	Victim(std::string);
	Victim(Victim const &);
	~Victim(void);
	Victim &operator=(Victim const &);

	// Getters
	std::string getName(void) const;

	// Setters
	void setName(std::string);

	// Methods
	std::string introduce(void) const;
	void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &, Victim const &);
#endif
