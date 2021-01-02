/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:33:51 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 19:12:39 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
#define SORCERER_H

#include "./Victim.hpp"
#include <iostream>
#include <ostream>

class Sorcerer
{
	// Canonical form
  private:
	Sorcerer(void); // Private default constructor
	std::string _name;
	std::string _title;

  public:
	Sorcerer(std::string, std::string);
	Sorcerer(const Sorcerer &);
	Sorcerer &operator=(Sorcerer const &);
	~Sorcerer(void);

	// Methods
	std::string introduce(void) const;
	void polymorph(Victim const &) const;

	// Getters
	std::string getName(void) const;
	std::string getTitle(void) const;
};

std::ostream &operator<<(std::ostream &, Sorcerer const &);

#endif
